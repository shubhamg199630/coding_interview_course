//  https://www.interviewbit.com/problems/cycle-in-undirected-graph/


// Logic is same is finding cycle is directed graph but here new think came is that never visit your immidiate parent who is called you then you will find cycle 
//  to it that is not so . so new varraibale used find parent.



void addedge(vector <vector <int>> &graph, int source, int dest)
{
    graph[source].push_back(dest);
    graph[dest].push_back(source);
}
int dfsutill(vector <vector <int>> &graph,vector <bool> &vis, 
                int curr,set <int> &s,int past)
{
    for (int i=0;i<graph[curr].size();i++)
    {
        int x=graph[curr][i];
       // cout<<past<<" "<<x<<endl;
        if (past==x)
            continue;
        //cout<<x;
        auto itr=s.find(x);
        bool b=itr!=s.end();
       // cout<<b;
        if (s.find(x)!=s.end())
            return 1;
        if (vis[x]==false)
        {
            vis[x]=true;
            s.insert(x);
            if (dfsutill(graph,vis,x,s,curr)==1)
                return 1;
            s.erase(x);
        }
    }
    return 0;
}
int dfs(vector <vector <int>> &graph, int V)
{
    vector <bool> vis(V, false);
    set <int> s;
    for (int i=1;i<V;i++)
    {
        if (vis[i]==false)
        {
            s.insert(i);
            vis[i]=true;
            if (dfsutill(graph,vis,i,s,0)==1)
            {
                return 1;
            }
            s.erase(i);
        }
    }
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector <vector <int>> graph;
    vector <int> temp;
    for (int i=0;i<A+1;i++)
        graph.push_back(temp);
    for (int i=0;i<B.size();i++)
        addedge(graph, B[i][0], B[i][1]);
    // for (int i=1;i<=A;i++)
    // {
    //     for (int j=0;j<graph[i].size();j++)
    //     {
    //         cout<<i<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dfs(graph, A+1);
}
