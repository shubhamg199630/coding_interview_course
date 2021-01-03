//   https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/description/

/*

Given n, i.e. total number of nodes in an undirected graph numbered from 1 to n and an integer e, i.e. total number of edges in the graph. Calculate the total number of connected components in the graph. A connected component is a set of vertices in a graph that are linked to each other by paths.

Input Format:

First line of input line contains two integers n and e. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. 

Output Format:

For each input graph print an integer x denoting total number of connected components.

Constraints:

All the input values are well with in the integer range.

SAMPLE INPUT 
8 5
1 2
2 3
2 4
3 5
6 7
SAMPLE OUTPUT 
3



*/


// Logic is very simple just use bfs / dfs to traverse the given graph and if it is diconnected then select no visited vertex again and start dfs/bfs .
// no of times you need run dfs / bfs on unvisited vertex is no of connected component



#include<bits/stdc++.h>
using namespace std;
void addedge(vector <vector <int>> &g, int s,int d)		// function to add undirected edge
{
	g[s].push_back(d);
	g[d].push_back(s);
}
void dfs(vector <vector <int>> &g, int curr, vector <bool> &vis)  // simple dfs code 
{
	vis[curr]=true;
	for (int i=0;i<g[curr].size();i++)
	{
		int x=g[curr][i];
		if (vis[x]==false)
			dfs(g,x, vis);
	}
}
int no_of_connected_comp(vector <vector <int>> &g )			// no of connected component using dfs (node edge start from 1 to n)
{
	vector <bool> vis(g.size(),0);
	int c=0;
	for (int i=1;i<g.size();i++)
	{
		if (vis[i]==false)
		{
			c++;
			dfs(g, i,vis);
		}
	}
	return c;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector <vector <int>> g (n+1,vector <int> (0,0) );		// graph start from 0 to n
	for (int i=0;i<e;i++)
	{
		int s, d;
		cin>>s>>d;
		addedge(g,s,d);
		
	}
	cout<<no_of_connected_comp(g);
}