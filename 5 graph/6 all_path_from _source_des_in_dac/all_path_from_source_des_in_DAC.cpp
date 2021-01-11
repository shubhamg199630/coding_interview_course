//  https://leetcode.com/problems/all-paths-from-source-to-target/


/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
Example 3:

Input: graph = [[1],[]]
Output: [[0,1]]
Example 4:

Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
Example 5:

Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
The input graph is guaranteed to be a DAG.

*/


// we have to print all path in a DAC , So cycle is not present here . so we can easily print this.
// Now our aim is not print all the possible path so we will use dfs and store the current path in a vector ., one it reach to destination we will copy that path
// and we will do this many times.



class Solution {
public:
    void dfs(vector<vector <int>> &g,int curr, vector <vector <int>> &ans, vector <int> &temp)
    {
        temp.push_back(curr);
        if (curr==g.size()-1)
            ans.push_back(temp);
        for (int i=0;i<g[curr].size();i++)
        {
            int x=g[curr][i];
            dfs(g,x,ans,temp);
        }
        temp.pop_back();
    }
    vector <vector <int>> all_path(vector <vector <int>> &g)
    {
        vector <int> temp;
        vector <vector <int>> ans;
            dfs(g,0,ans,temp);
        return ans;
    }
        
        
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        return all_path(graph);        // from source to destination
        
    }
};