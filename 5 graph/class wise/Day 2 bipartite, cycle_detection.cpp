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
    void single_source_dfs(vector <vector <int>> &g,int curr,vector <int> &vis,vector <int> &dis, int curr_dis)
    {
        vis[curr]=1;
        dis[curr]=curr_dis;
        for (int child : g[curr])
        {
            if (vis[child]==false)
                single_source_dfs(g,child,vis,dis,curr_dis+1);
        }
    }
    bool bipartite(vector <vector <int>> &g,int curr,int c,vector <int> &col,vector <int> &vis)
    {
        //cout<
        vis[curr]=1;
        col[curr]=c;
        for (int child : g[curr])
        {
            if (vis[child]==0)          // not visited
            {
                if (bipartite(g,child,!c,col,vis)==false)
                        return false;
            }
            else                    // visited
            {
                if (col[child]==col[curr])
                    return false;
            }
        }
        return true;
    }
    bool cycle_detection(vector <vector <int>> &g, int curr, vec(int) &vis, int par)
    {
        vis[curr]=true;
        //cout<<curr<<" "<<par<<endl;
        for (int child : g[curr])
        {
            if (vis[child]==false )          // node is not visited
            {
                if (cycle_detection(g, child,vis,curr)==true)
                    return true;
            }
            else            // node is visited
            {
                if (child !=par)            // ancestor  backedge detected  //cycle detected
                {
                   // cout<<"asasa"<<child<<" "<<par<<endl;
                    return true;
                }
            }
        }
        return false;
    }


    int main()
    {
        int v,e;
        cin>>v>>e;      // (0,v-1)
        v++;


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
        /*cout<<"dsd";
        for (int i=1;i<v;i++)
        {
            cout<<i<<" ->";
            for(int j=0;j<g[i].size();j++)
                cout<<g[i][j]<<" ->";
            cout<<endl;
        }
        */

        vector <int> vis(v, false);
        //dfs(g,0,vis);
        //cout<<no_of_connect_comp(g,vis)<<endl;
        /*vector <int> dis(v,-1);
        single_source_dfs(g,1,vis,dis,0);
        for (int i=0;i<v;i++)
            cout<<i<<"->"<<dis[i]<<endl;
    */
        //vector <int> col(v,-1);
        //cout<<bipartite(g,1,0,col,vis);
        cout<<cycle_detection(g,1,vis,-1);

    }
