//  https://www.interviewbit.com/problems/subsets-ii/

/*Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

*/

//Logic   -----  Tree structure
//                         [  ]                  // add [] to ans
//                        / |  \   \  
//                       /  |   \   \
//                      [1] [1]c[1]c [2]            // add [1], [2] and [3]
//                      /\ \         
//                     /  \ \      
//                    /    \ \       
//                [1,1] [1,1]c[1,2]
//                /   \        
//               /     \    
//              /       \   
//           [1,1,1]    [1,1,2] 
//             /
//            /
//           /
//       [1,1,1,2]                

// so condition for copy is i>curr && (i>0&&a[i]==a[i-1])           // copy condition do not call that tree.


void final(vector<int> &A,int curr,vector<int> temp, vector<vector<int>> &res)
{
    int n=A.size(),flag=0;
    res.push_back(temp);
    
    if (curr==n)
        return ;
    else 
    {
        for (int i=curr;i<n;i++)
        {
            if (i>0&&A[i]==A[i-1])
                continue;
            vector <int > temp1(temp);
            
            temp1.push_back(A[i]);
            final(A,i+1, temp1, res);
        }
    }
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    if (A.size()){
    sort (A.begin(), A.end());
    }
    vector < vector <int > > res;
    vector < int > temp ; 
    final(A,0, temp, res); 
    return res;
    
}
