// https://www.interviewbit.com/problems/permutations/

//Given a collection of numbers, return all possible permutations.
//
//Example:
//
//[1,2,3] will have the following permutations:
//
//[1,2,3]
//[1,3,2]
//[2,1,3] 
//[2,3,1] 
//[3,1,2] 
//[3,2,1]
//
//





//              [1,2,3]\
//                 / |    \
//                /  |     \
//               /   |       \
//            [1,2,3] [2,1,3] [3, 2 1] \
//            /   |      |  \         \ \
//           /    |      |  \          \ \
//          /     |      |    \        \  \ 
//         /      |      |      \         \  \
//        [1,2,3] [1,3,2] [2,1,3] [2,3,1]  [3,2,1] [3,1,2]
//            
                     
                     
                     
                     
#define ll long long
#define mod 1000000007
#define vec vector <int>
#define vecvec vector<vector <int>>
#define pb push_back
void print(vector <int> curr)
{
    for (int i=0;i<curr.size();i++)
        cout<<curr[i];
    cout<<endl;
}
void permutation(vec a, int curr, vecvec &ans)
{
    if (curr==a.size())
        ans.pb(a);
    else
    {
        for (int i=curr;i<a.size();i++)
        {
            swap(a[i],a[curr]);
            permutation(a,curr+1,ans);
            swap(a[i],a[curr]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector <int> curr;
    vector <vector <int>> ans;
    permutation(A,0,ans);
    return ans;
    
}

                    