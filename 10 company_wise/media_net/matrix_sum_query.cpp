#include<bits/stdc++.h>
using namespace std;

vector <vector <int>> created_dp(vector <vector <int>> &a)
{
    vector <vector <int>> dp(a.size(),vector <int> (a[0].size(),0));
    dp[0][0]=a[0][0];
    for (int i=1;i<a.size();i++)
    {
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for (int j=1;j<a[0].size();j++)
    {
        dp[0][j]=dp[0][j-1]+a[0][j];
    }
    for (int i=1;i<a.size();i++)
    {
        for (int j=1;j<a[0].size();j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    return dp;
}
int sum_query(vector <vector <int>> &dp,int r1,int c1, int r2, int c2)
{
    int res=dp[r2][c2];
    if (r1>0)
        res=res-dp[r1-1][c2];
    if (c1>0)
        res=res-dp[r2][c1-1];
    if (r1 > 0 and c1>0)
        res=res+dp[r1-1][c1-1];
    return res;
}
int bs(vector <vector <int>> &dp, int l, int r,int x, int y,int temp, int &k)
{
    //cout<<l<<r<<endl;
    if (l>r)
        return temp;
    else
    {
        int mid=(l+r)/2;
        if (mid%2==0)
            mid--;
        int curr=sum_query(dp,x-mid/2,y-mid/2,x+mid/2,y+mid/2);
        if (curr>k)
            return bs(dp,l,mid-2,x,y,temp,k);
        else
        {
            temp=curr;
            return bs(dp, mid+2,r,x,y,temp,k);
        }
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector <vector<int>> a(m,vector <int> (n,0));
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector <vector <int>> sum=created_dp(a);
    int q;
    cin>>q;
    while (q--)
    {
        int x,y,k;
        cin>>x>>y>>k;
        int temp=min(min(y,n-1-y),min(x,m-1-x));
        cout<<bs(sum,1,2*temp+1,x,y,-1, k)<<endl;
    }
}
