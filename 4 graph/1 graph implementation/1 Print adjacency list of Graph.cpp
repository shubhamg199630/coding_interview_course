#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void addedge(vector <vector<int>> &graph,int s,int d)
{
    graph[s].push_back(d);
    graph[d].push_back(s);
}
void printgraph(vector <vector<int>> &graph)
{
    int m=graph.size();
    for (int i=0;i<m;i++)
    {
        cout<<i;
        for (int j=0;j<graph[i].size();j++)
        {
            cout<<"->"<<" "<<graph[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m,s,d;
        cin>>n>>m;
        vector <vector <int>> graph(n,vector <int> (0,0));
        for (int i=0;i<m;i++)
        {
            cin>>s>>d;
            addedge(graph,s,d);
        }
        printgraph(graph);
        graph.clear();
    }
}

