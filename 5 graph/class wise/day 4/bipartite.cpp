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
bridge_detection(vector <vector <int>> &g,int curr,int par,
                 vector <int> &vis,vector <int> &in,vector <int> &low)
{
    vis[curr]=1;
    in[curr]=timer;
    low[curr]=timer;
    timer++;
    for (int child: g[curr])
    {
        if (child ==par)       // parent edge
        {
            continue;
        }
         // it is visited and not parent it means ancestor
                                        // it is back edge;
        else if (vis[child]==true)      // visited edge
        {
            low[curr]=min(low[curr],in[child]);  // this is backedge update lower
        }
        else
        {
            //edge is forward edge;
            bridge_detection(g,child,curr,vis, in ,low);
            if (low[child]>in [curr])  // bridge condition
                cout<<curr<<" "<<child<<" Bridge\n";
            low[curr]=min(low[curr],low[child]);  // decrese my
        }
    }
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
    bridge_detection(g,1,par,vis,in,low);
    for (int i=1;i<v;i++)
        cout<<in[i]<<" ";
    cout<<endl;
    for (int i=1;i<v;i++)
        cout<<low[i]<<" ";
    cout<<endl;

}
