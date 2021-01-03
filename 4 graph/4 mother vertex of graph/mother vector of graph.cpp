void dfsutill(vector <int> g[], int curr,vector <int> &vis)
{
    vis[curr]=true;
    for (int i=0;i<g[curr].size();i++)
    {
        if (vis[g[curr][i]]==false)
        {
            dfsutill(g,g[curr][i],vis);
        }
    }
}
int dfs_mother(vector<int> g[], int N, int mother)
{
    vector <int> vis(N,false);
    dfsutill(g,mother,vis);
    for (int i=0;i<N;i++)
    {
        if (vis[i]==false)
        {
            return 0;
        }
    }
    return 1;
}
int dfs(vector<int> g[], int N)
{
    vector <int> vis(N,false);
    int ans=-1;
    for (int i=0;i<N;i++)
    {
        if (vis[i]==false)
        {
            ans=i;
            dfsutill(g,i,vis);
        }
    }
    return ans;
}

int findMother(int V, vector<int> g[]) 
{ 
    int mother=dfs(g,V);
    if (dfs_mother(g,V,mother)==1)
        return mother;
    else 
        return -1;
} 