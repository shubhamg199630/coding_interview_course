#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x)vector<vector <x>>
#define pb push_back

using namespace std;

struct node             // creating node for vertex and weight
{
    int v;
    int weight;
};

node create_node(int des, int w)                    // function to create new node  and return temp
{
    node temp;
    temp.v=des;
    temp.weight=w;
    return temp;
}

void addedge(vecvec(node) &graph, int src, int dest, int w)               // adding node to adj list.
{
    node temp=create_node(dest,w);                      // undirected graph so only minimum selected.
    graph[src].push_back(temp);
    temp=create_node(src,w);
    graph[dest].push_back(temp);
}

vector <int> prims(vector <vector <node>> &g,int s)
{
    int n=g.size();
    vector <bool> vis (n,false);
    vector <int> path(n,INT_MAX);           // putting infinity
    path[s]=0;
    multimap <int,int> heap ;       // min heap using map will give log n every case

    heap.insert({path[s],s});

    vec(int) parent(n,-1);          // creating vector for parent node
    while (!heap.empty())
    {
        auto itr=heap.begin() ;          // find min in heap
        int d=(itr->second);
        heap.erase(itr);    // removing that element from heap;
        if (vis[d]==true)
            continue;
        vis[d]=true;
        for (int i=0;i<g[d].size();i++)         // loop for relaxing of edge
        {
            int des=g[d][i].v;
            if (vis[des]==false)
            {
                if ((g[d][i].weight)<path[des])
                {
                    path[des]=g[d][i].weight;
                    heap.insert({path[des],des});
                    parent[des]=d;
                }
            }
        }
    }
    return path;
}

int main()
{
    int v,e;
    cin>>v>>e;      // vertex and edges
    vecvec(node) graph(v,vec(node) (0));            // creating graph of   vector(0 to v-1) and each having size zero.
    for (int i=0; i<e; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        addedge(graph,s,d,w);           // source and distination
    }
    int src;
    cin>>src;           // enter souce node to start;
    vector <int> ans=prims(graph,src);       // calling dijkstra using src
    cout<<"MIN DISTANCE FROM"<<src<<endl;
    for (int i=0;i<ans.size();i++)
    {
        cout<<i<<"->"<<ans[i]<<endl;
    }
}
