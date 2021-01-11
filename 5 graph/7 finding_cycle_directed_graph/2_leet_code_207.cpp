/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5


*/

//------solution
// same solution but vector is used in place of set as set is not working correctly in leet code compiler.

class Solution {
public:
    void addedge(vector <vector <int>> &g, int s, int d)
    {
        g[s].push_back(d);
    }
    bool dfs(vector <vector <int>> &g, int curr, vector <bool> &vis,vector <bool> &s)
    {
        vis[curr]=true;
        s[curr]=true;
        for (int i=0;i<g[curr].size();i++)
        {
            int x=g[curr][i];
            if (s[x]==true)
            {
                return 1;
            }
            if (vis[x]==false)
            {
                if (dfs(g,x,vis,s)==1)
                    return 1;
            }
        }
        s[curr]=false;
        return 0;
    }
    bool findcycle(vector <vector <int>> &g)
    {
        vector <bool> vis(g.size(), false);
        vector<bool> s(g.size(),false);
        for (int i=0;i<g.size();i++)
        {    
            if (vis[i]==false)
            {
                if (dfs(g,i,vis,s))
                    return 1;
            }
        }
        return 0;
    }
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            //make graph first
        vector <vector <int>> graph(numCourses, vector <int> (0, 0) );
        for (int i=0;i<prerequisites.size();i++)
        {
            addedge(graph, prerequisites[i][1],prerequisites[i][0]);
        }
        return !findcycle(graph);
    }
    
};