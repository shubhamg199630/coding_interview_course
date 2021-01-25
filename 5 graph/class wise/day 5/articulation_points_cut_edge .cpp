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
int timer=1;
vector <int> cut(1000,0);
cut_vertex_detection(vector <vector <int>> &g,int curr,int par,
                 vector <int> &vis,vector <int> &in,vector <int> &low)
{
    vis[curr]=true;
    in[curr]=timer,low[curr]=timer;
    timer++;
    int vis_times=0;
    for (int child : g[curr])
    {
        if (child ==par)        // edge to the parent
            continue;
        else if (vis[child]==true)     // edge which is not parent and visited
        {                               // it is a backedge
            low[curr]=min(low[curr],in[child]);
        }
        else
        {
            //edge which not parent and not visited
            // forward edge
            cut_vertex_detection(g,child,curr,vis,in,low);
            low[curr]=min(low[curr],low[child]);
            if (low[child]>=in[curr]&&par!=-1)      // not root also
                cut[curr]=1;
            vis_times++;
        }
    }
    if (vis_times>=2&&par==-1)      // root having two non visited children
        cut[curr]=1;
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

    vector <int> vis(v, false);
    vector <int> in(v,0);
    vector <int> low(v,0);
    int par=-1;
    timer=1;
    cut_vertex_detection(g,1,par,vis,in,low);


    for (int i=1;i<v;i++)
        cout<<in[i]<<" ";
    cout<<endl;
    for (int i=1;i<v;i++)
        cout<<low[i]<<" ";
    cout<<endl;

    for (int i=1;i<v;i++)
    {
        if (cut[i]==1)
            cout<<"THIS is a cut vertex"<<i<<endl;
    }
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
