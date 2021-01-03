
void dfsutill(vector <int> g[], int curr, vector <int> &dfsans,vector <int> &vis)
{
    vis[curr]=true;
    for (int i=0;i<g[curr].size();i++)
    {
        if (vis[g[curr][i]]==false)
        {
            dfsans.push_back(g[curr][i]);
            dfsutill(g,g[curr][i],dfsans,vis);
        }
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    vector <int> vis(N,false);
    vector <int> dfsans;
    dfsans.push_back(0);
    for (int i=0;i<N;i++)
    {
        if (vis[i]==false)
        {
            dfsutill(g,i,dfsans,vis);
        }
    }
    return dfsans;
}
