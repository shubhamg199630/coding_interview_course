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
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void dfs(vecvec(int) &a, int x, int y, vecvec(bool) &vis)
{
    vis[x][y]=1;
    for (int i=0;i<4;i++)
    {
        int x_=x+dx[i];
        int y_=y+dy[i];
        // x_ and y_ are adjacent points
        if (x_==-1||x_==a.size()||y==-1||y==a[0].size())
            continue;
        else if (a[x_][y_]==1&&vis[x_][y_]==false)
            dfs(a,x_,y_,vis);
    }
}

int no_of_island(vecvec(int) &a, int row, int col)
{
    int c=0;

    vector <vector <bool>> vis(row,vector<bool> (col,false));

    for (int i=0;i<row;i++)
    {
        for (int j=0;j<col;j++)
        {
            int x=a[i][j];
            if (vis[i][j]==false&&x==1)     // not visited and land part
            {
                c++;
                dfs(a,i,j,vis);
            }
        }
    }
    return c;
}



int main()
{
    vecvec(int) a;
    int n, m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        vec(int) temp;
        for (int j=0;j<m;j++)
        {

            int x;
            cin >>x;
            temp.pb(x);
        }
        a.pb(temp);
    }
    cout<<no_of_island(a,n ,m);

}
