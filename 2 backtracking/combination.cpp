//  https://www.interviewbit.com/problems/combinations/

//Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
//
//Make sure the combinations are sorted.
//
//To elaborate,
//
//Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
//Entries should be sorted within themselves.
//Example :
//If n = 4 and k = 2, a solution is:
//
//[
//  [1,2],
//  [1,3],
//  [1,4],
//  [2,3],
//  [2,4],
//  [3,4],
//]




//          ---- logic
//            [       ]
//           /        | \    \
//          /         |  \    \
//         /          |   \    \
//        [1]         [2]  [3]  [4]
//       / | \         |  \  \
//      /  |  \        |   \  \
//     /   |   \       |    \  \
//    [1,2][1,3][1,4] [2,3] [2,4] [3,4]



void final(vector <int> &vec, int curr, vector <vector <int>> &ans,
                vector <int > &temp, int B)
{
    int n=vec.size();
    if (temp.size()==B)
        ans.push_back(temp);
    else if (curr==n)
        return ;
    for (int i=curr;i<vec.size();i++)
    {
        vector <int > temp1 (temp);
        temp1.push_back(vec[i]);
        final(vec, i+1, ans , temp1,B);
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector <int > vec;
    int i,n;
    for (i=0;i<A;i++)
    {
        vec.push_back(i+1);
    }
    vector <vector < int > > ans;
    vector < int>  temp;
    final (vec, 0, ans, temp, B);
    return ans;
}

