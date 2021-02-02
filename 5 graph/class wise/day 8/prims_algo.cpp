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
    int c=0,mst_cost=0;
    while (c<v)
    {
        pair <int, int> p=q.top();
        q.pop();
        if (vis[p.S]==true)
            continue;
        mst_cost+=p.F;
        //cout<<p.F<<" ";           // removing it from queue
        c++;
        vis[p.S]=true;
        for ( pair<int,int>  child : g[p.S])
        {
            int des=child.S;
            int wt=child.F;
            if (vis[des]==false)
            {
                if (wt<dis[des])            // comparing weight with old weight
                {
                    dis[des]=wt;
                    q.push({-wt,des});

                }
            }
        }
    }
    cout<<abs(mst_cost);
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

