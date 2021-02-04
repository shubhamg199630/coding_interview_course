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
void prims(vector <vector <pair <int ,int >>> &g, int start )
{
    int v=g.size();     // no of vertex in graph
    vector<int> dis(v,INT_MAX);      // giving infinity to all
    vector <bool> vis(v,false);
    priority_queue<pair<int,int>> q;        // maximum heap
    dis[start]=0;
    q.push({dis[start],start});      // first element inserted in priority queue
    while (!q.empty())
    {
        pair <int, int> p=q.top();
        q.pop();
        if (vis[p.S]==true)
            continue;
        //cout<<p.F<<" ";           // removing it from queue
        vis[p.S]=true;
        for ( pair<int,int>  child : g[p.S])
        {
            int des=child.S;
            int wt=child.F;
            if (vis[des]==false)
            {
                if (dis[p.S]+wt<dis[des])            // comparing weight with old weight
                {
                    dis[des]=wt+dis[p.S];
                    q.push({-dis[des],des});
                }
            }
        }
    }
    for (int i=0;i<v;i++)
    {
        cout<<dis[i]<<" ";
    }
}

int main()
{
    ll v,e;
    cin>>v>>e;
    vector <vector <pair <int ,int >>> g( v,vector <pair<int,int>>(0));

    for (int i=0;i<e;i++)
    {
        int s,d,wt;
        cin>>s>>d>>wt;
        g[s].pb({wt,d});
        g[d].pb({wt,s});
    }
    int start;
    cin>>start;         // starting node
    prims(g,start);
}

