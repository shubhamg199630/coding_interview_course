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
vector <int> par;
vector <int> rank_;


struct edge
{
    int s;
    int d;
    int wt;
};

int find_(int v)
{
    if (par[v]==-1)
        return v;
    else
        return par[v]=find_(par[v]);            // path compression
}

void union_(int a, int b)
{
    int p1=find_(a);        // parent of a
    int p2=find_(b);        // parent of b;

    if (p1!=p2)
    {
        if (rank_[p1]>rank_[p2])
            par[p2]=p1;             // parent of p2 becomes p1
        else if (rank_[p2]>rank_[p1])
            par[p1]=p2;
        else
        {
            par[p2]=p1;
            rank_[p1]+=1;
        }
    }
    else
    {
        cout<<"Cycle detected"<<a<<" "<<b<<endl;
    }

}
bool comparator (edge a, edge b)
{
    if (a.wt<b.wt)
        return 1;
    else
        return 0;
}
void kruskal(vector <edge> &edges, int v)
{
    sort(edges.begin(),edges.end(),comparator);// edges sort
    vector <edge> mst;
    int i=0,c=0;
    while (c<v-1&&i<edges.size())
    {
        int p1=find_(edges[i].s);
        int p2=find_(edges[i].d);
        if (p1!=p2)     // not cycle
        {
            union_(p1,p2);
            mst.pb(edges[i]);
            c++;
        }
        i++;
    }
    int cost=0;
    for (int i=0;i<mst.size();i++)
    {
        cout<<mst[i].wt<<" ";
        cost=cost+mst[i].wt;
    }
    cout<<cost<<endl;
}
int main()
{
    int v,e;
    cin>>v>>e;

    for (int i=0;i<v;i++)
    {
        par.pb(-1);     // it will add v times -1
        rank_.pb(0);

    }
    vector <edge> edges;

    for (int i=0;i<e;i++)       // for edge
    {
        int s,d,wt;
        edge temp;

        cin>>temp.s>>temp.d>>temp.wt;
        edges.pb(temp);
    }
    kruskal(edges,v);

    /*int c=0;    // no of connected compenets

    for (int i=0;i<v;i++)
    {
        if (par[i]==-1)
            c++;
        cout<<par[i]<<" ";
    }
    cout<<endl;
    cout<<c<<endl;*/
}


