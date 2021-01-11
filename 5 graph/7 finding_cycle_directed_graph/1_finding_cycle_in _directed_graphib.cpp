/*Problem Description

https://www.interviewbit.com/problems/cycle-in-directed-graph/

Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if cycle is present else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
Input 2:

 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation*
Explanation 1:

 The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
Explanation 2:

 The given graph doesn't contain any cycle.
*/



//---------------------------
//Logic is find the backedge in the graph. to find that we need an edge that is pointing to the acestor of parents nodes . Hence we used 
//a set that represented the current ancestors and if a edge is pointing to ancestor then cycle is present.

//code
void addedge(vector <vector <int>> &graph, int source, int dest)		// for adding edge in graph
{
    graph[source].push_back(dest);						
}

int dfsutill(vector <vector <int>> &graph,vector <bool> &vis, int curr,set <int> &s)				// dfs function with set to represent ancestor.
{
    s.insert(curr);										// adding current node to ancestor list.
    vis[curr]=true;
    for (int i=0;i<graph[curr].size();i++)
    {
        int x=graph[curr][i];								
        if (s.find(x)!=s.end())									// if the edge is present in  ancestor list then cycle is present.
            return 1;
        if (vis[x]==false)									// recursive call for next adjecent edge.
        {
            if (dfsutill(graph,vis,x,s)==1)
                return 1;
        }
    }
    s.erase(curr);						// erasing the current vertex from ancestor list as the given function list is pop .
    return 0;
}
int cycle_finding_directed_graph(vector <vector <int>> &graph, int V)					// function to find cycle in directed graph with help of dfs
{
    vector <bool> vis(V, false);
    set <int> s;
    for (int i=1;i<V;i++)
    {
        if (vis[i]==false)
        {
            if (dfsutill(graph,vis,i,s)==1)
            {
                return 1;
            }
        }
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {						
    vector <vector <int>> graph(A+1, vector <int> (0,0));			// creating graph
    for (int i=0;i<B.size();i++)
        addedge(graph, B[i][0], B[i][1]);					// adding adjency list to graph.			
    return cycle_finding_directed_graph(graph, A+1);
}
