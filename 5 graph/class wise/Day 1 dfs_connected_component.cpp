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

void dfs(vector <vector <int>> &g, int curr,vector <int> &vis)
{
    vis[curr]=true;
    //cout<<curr<<" ";
    for (int child : g[curr])
    {
        if (vis[child]==false)
            dfs(g,child,vis);
    }
}

int no_of_connect_comp(vector <vector <int>> &g,vector <int> &vis)
{
    int c=0;
    for (int i=0;i<g.size();i++)
    {
        if (vis[i]==false)
            dfs(g,i, vis),c++;
    }
    return c;
}


int main()
{
    int v,e;
    cin>>v>>e;      // (0,v-1)


    /*4 4   // 0 to 3 vertex
    0 1
    2 1
    3 1
    2 3
    */

    vector <vector <int>> g(v,vector <int> (0,0));
    for (int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;      // 1-->2
        g[s].pb(d);
        g[d].pb(s);
    }
   /* cout<<"dsd";
    for (int i=0;i<v;i++)
    {
        cout<<i<<" ->";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ->";
        cout<<endl;
    }*/

    vector <int> vis(v, false);
    //dfs(g,0,vis);
    cout<<no_of_connect_comp(g,vis)<<endl;
}
