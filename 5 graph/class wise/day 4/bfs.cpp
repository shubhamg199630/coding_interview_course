#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x
using namespace std;

void bfs(vector <vector <int>> &g )
{
    vector <int> vis(g.size(), false);
    queue <int> q;
    q.push(1);   // starting vectex
    vis[1]=true;
    while (!q.empty())  // while queue in not empty
    {
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();        //removing it from queue;
        for (int child : g[curr])
        {
            if (vis[child]==false)
            {
                vis[child]=true;
                q.push(child);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int v,e;
    cin>>v>>e;      // (0,v-1)
    v++;


    /*4 4   // 0 to 3 vertex
    0 1
    2 1
    3 1
    2 3
    */

    vector <vector <int>> g(v,vector <int> (0,0));
    for (int i=0; i<e; i++)
    {
        int s,d;
        cin>>s>>d;      // 1-->2
        g[s].pb(d);
        g[d].pb(s);
    }
    bfs(g);
}
