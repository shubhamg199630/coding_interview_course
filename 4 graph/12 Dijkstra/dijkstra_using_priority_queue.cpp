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
void addedge(vecvec(pr(ll,ll)) &graph,ll s, ll d, ll w )           // adding edge to graph
{
    graph[s].pb({w,d});             // adding pair to s ;
    graph[d].pb({w,s});             // adding pair to d
                                    // note that the graph in undirected here.
}
vec(ll) dijkstra(vecvec(pr(ll,ll))  &g, ll src)
{
    ll n=g.size();
    vec(ll) distance(n,INT_MAX);           // path vector for min distance information
    priority_queue<pr(ll,ll)> pq;       // priority queue so that we can use it as
    distance[src]=0;
    vec(ll) parent(n,-1);                  // everyone is the parent of it self.
    vec(bool ) vis (n, false);            // vis array for find vis;
    pq.push({distance[src],src});


    while (!pq.empty())     // while heap is not empty
    {
        auto itr=pq.top();
        ll s=itr.S;           // vectex
        pq.pop();           // poping the element from queue
        if (vis[s])           // if vertex is visited
            continue;
        vis[s]=true;

        for (pair <ll,ll > p : g[s])          // p is a pair point to first element of g[s] and will ++ next time
        {
            ll d=p.S ;           // adj vertex of g[s]
            ll w=p.F;             // current edge weight
            //cout<<d<<" ";
            if (vis[d]==false)
            {
                if (distance[s]+w<distance[d])      //relaxing of edge
                {
                    distance[d]=distance[s]+w;
                    pq.push({-distance[d],d});      // multipy by -1 so that minimum will come very time.
                    parent[d]=s;
                }
            }
        }
    }
    return distance;
}


int main()
{
    ll v,e;
    cin>>v>>e;      // vertex and edges
    vecvec(pr(ll,ll)) graph(v,vec(pr(ll,ll)) (0));            // creating graph of   vector(0 to v-1) and each having size zero.
    for (ll i=0; i<e; i++)
    {
        ll s,d,w;
        cin>>s>>d>>w;
        addedge(graph,s,d,w);           // source and destination
    }
    ll src;
    cin>>src;           // enter source node to start;

    vector <ll> ans=dijkstra(graph,src);
    cout<<"MIN DISTANCE FROM "<<src<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<i<<"->"<<ans[i]<<endl;
    }
}