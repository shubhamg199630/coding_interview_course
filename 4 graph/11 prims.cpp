#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

struct node             // vertex and weight
{
    int v;
    int weight;
};

node create_node(int des, int w)                    // function to create new node
{
    node temp;
    temp.v=des;
    temp.weight=w;
    return temp;
}

void addedge(vector <vector <node>> &graph, int src, int dest, int w)               // adding node to adj list.
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
    vector <int> set_min(n,INT_MAX);           // putting infinity
    set_min[s]=0; vis[s]=true;
    multimap <int,int> heap ;       // min heap using map will give log n every case
    for (int i=0;i<n;i++)
    {
        heap.insert({set_min[i],i});
    }
    int c=1;
    while (c<n)
    {
        c++;
        auto itr=heap.begin() ;          // find min in hheap
        int d=(itr->second);
        vis[d]=true;
        set_min[d]=itr->first;
        heap.erase(itr);    // removing that element from heap;
        for (int i=0;i<g[d].size();i++)         // loop for relaxing of edge
        {
            int des=g[d][i].v;
            if (vis[des]==false)
            {
                if ((g[d][i].weight)<set_min[des])
                {
                    //relaxing the edge in set_min and also in heap
                    auto itr_new=heap.find(set_min[des]);
                    while (itr_new->second!=des)
                        itr_new++;
                    heap.erase(itr_new);
                    set_min[des]=g[d][i].weight;
                    heap.insert({set_min[des],des});
                }
            }
        }
    }
    return set_min;
}

int main()
{
    int v,e;
    cin>>v>>e;      // vertex and edges
    vector <vector <node>> graph(v,vector <node> (0));      // creating graph of   vector(0 to v-1) and each having size zero.

    for (int i=0; i<e; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        addedge(graph,s,d,w);           // source and distination
    }
    int src;
    cin>>src;
    vector <int> ans=prims(graph,src);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
