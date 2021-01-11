vector <int> bfs(vector<int> g[], int N) 
{
    queue <int > q;
    vector <int> bfs;
    vector <int> vis(N,0);
    q.push(0);
    vis[0]=1;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        bfs.push_back(x);
        for (int i=0;i<g[x].size();i++)
        {
            if (vis[g[x][i]]!=1)
            {
                q.push(g[x][i]);
                vis[g[x][i]]=1;
            }
        }
    }
    return bfs;
}
