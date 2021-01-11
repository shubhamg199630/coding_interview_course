/*There are a total of n courses you have to take labelled from 0 to n - 1.

Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.

Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.

If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.


*/

//------ As for topological sort we need acyclic graph. so we need to check cycle in directed graph. For topological sort we need use dfs and add on line add in stack
// the curr element onces the last element is done.

//https://leetcode.com/problems/course-schedule-ii/


class Solution {
public:
    
    void addedge(vector <vector <int>> &g, int s, int d)
    {
        g[s].push_back(d);
    }
    bool dfs(vector <vector <int>> &g, int curr,vector <bool> &vis,
            vector <bool> &s, stack <int> &top_order )
    {
        vis[curr]=true;
        s[curr]=true;
        for (int i=0;i<g[curr].size();i++)
        {
            int x= g[curr][i];
            if (s[x]==true)
                return 1;
            if (vis[x]==false)
            {
                if (dfs(g,x,vis, s, top_order)==true)
                    return 1;
            }
        }
        s[curr]=false ;                  //removing the current element from ancestor arary.
        top_order.push(curr);
        return 0;
    }
    vector <int> toplogical_sort(vector <vector <int>> &g)      // function for topological sort.
    {
        vector <bool> vis(g.size(), 0);         // visited array with all false;
        vector <bool> s(g.size(),0);            // current stack element for cycle detection in graph
        stack <int> top_order;             //stack used for storing topologocal order 
        for (int i=0;i<g.size();i++)
        {
            if (vis[i]==false)
                if (dfs(g,i, vis, s, top_order))
                    return {} ;          // return empty vector as cycle found;
        }
        vector <int> ans ;              // topological order as vector
        while (top_order.size())
        {
            int x=top_order.top();
            ans.push_back(x);
            top_order.pop();
        }
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <vector <int>> g(numCourses, vector <int> (0,0));
        for (int i=0;i<prerequisites.size();i++)
        {
            addedge(g, prerequisites[i][1], prerequisites[i][0]);   // adding edge is graph
        }
        return toplogical_sort(g);
    }
};