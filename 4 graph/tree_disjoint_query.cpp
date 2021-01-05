#include<bits/stdc++.h>
using namespace std;

struct node
{
    int parent;
    int rank;
};
int find_root(vector <node> &a )
{
    int root=-1;
    for (int i=0;i<a.size();i++)
    {
        if (a[i].parent==-1)
        {
            return i;
        }
    }
    return -1;
}
int dfs_utill(vector <vector <int>> &g, int root,vector <node> &a, vector <bool> &vis)     // dfs purpose is due to only because of rank.
{
    vis[root]=1;
    int temp=0;
    //cout<<root<<" asa"<<endl;
    for (int i=0; i<g[root].size(); i++)
    {
        int x=g[root][i];
        if (vis[x]==false)
        {
            temp+=(dfs_utill(g,x,a,vis)+1);
        }
    }
   // cout<<root<<" Asa" <<temp<<endl;
    a[root].rank=temp;
    return temp;
}
void dfs_for_rank(vector <vector <int>> &g, int root,vector <node> &a)
{
    vector <bool> vis(g.size(),0);
    dfs_utill(g,root, a, vis);
}
void print(vector <node> &a)
{
    for (int i=0;i<a.size();i++)
    {
        cout<<i<<" "<<a[i].parent<<" "<<a[i].rank<<endl;
    }
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector <node> a(v);   // v vertex from 0 to v-1;
   // fill(a.begin(),a.end(),-1);

    vector <vector <int>> g(v,vector <int> (0,-1));    // creating real graph so that
    for (int i=0;i<v;i++)
    {
       a[i].parent=-1;
       a[i].rank=0;
    }
    for (int i=0;i<e;i++)
    {
        int root,child;    // adding tree as root and child;
        cin>>root>>child;
        a[child].parent=root;
        g[root].push_back(child);
    }
    int root=find_root(a);
    dfs_for_rank(g,root,a);


    // calculating answer.
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        int s,d;
        cin>>s>>d;
        int temp=a[s].parent;
        a[s].parent=-1;
        a[d].rank-=a[s].rank;
    }

    print(a);
}
