/*Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

*/
//      https://www.interviewbit.com/problems/subset/


//Logic   -----  Tree structure
//                         [  ]                 // add [] to ans
//                        / |  \  
//                       /  |   \
//                      [1] [2]  [3]            // add [1], [2] and [3]
//                      /    |    
//                     /     |     
//                    /      |           
//                [1,2]    [2,3]
//                /
//               /
//              /
//              [1,2,3]
//              
//                            
void final(vector<int> &A,int curr,vector<int> temp, vector<vector<int>> &res)
{
    int n=A.size();
    res.push_back(temp);
    
    if (curr==n)
        return ;
    else 
    {
        for (int i=curr;i<n;i++)
        {
            vector <int > temp1(temp);
            temp1.push_back(A[i]);
            final(A,i+1, temp1, res);
        }
    }
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    if (A.size()){
    sort (A.begin(), A.end());
    }
    vector < vector <int > > res;
    vector < int > temp ; 
    final(A,0, temp, res); 
    return res;
    
}
