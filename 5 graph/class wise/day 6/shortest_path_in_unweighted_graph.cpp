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


void shortest_path(vecvec(int) &g,int v)
{
    vector <int> vis(v, false);
    vector <int> dis(v,-1);
    queue <int> q;
    vis[1]=true;
    q.push(1);
    dis[1]=0;       // putting first element as zero
    while (!q.empty())
    {
        int curr=q.front();     // geeting front element from queue
        q.pop();        // queue element is poped
        for (int child :g[curr])
        {
            if (vis[child]==false)
            {
                vis[child]=true;
                q.push(child);
                dis[child]=dis[curr]+1;
            }
        }
    }
    for (int x : dis)
        cout<<x<<" ";
    cout<<endl;
}


int main()
{
    int v,e;
    cin>>v>>e;      // (0,v-1)
    v++;

    vector <vector <int>> g(v,vector <int> (0,0));
    for (int i=0; i<e; i++)
    {
        int s,d;
        cin>>s>>d;      // 1-->2
        g[s].pb(d);
        g[d].pb(s);
    }

    shortest_path(g,v);

    /*
7 8
1 2
2 3
3 4
4 2
1 5
5 6
6 7
5 7*/
}
