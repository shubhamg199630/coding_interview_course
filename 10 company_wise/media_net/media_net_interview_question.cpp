#include<bits/stdc++.h>
#define ll long long
#define vec vector<int>
#define vecvec vector <vector <int>>
using namespace std;
int solve(vec &a, vec &b, int n, vec &dp)
{
    if (n<=0)
        return 0;
    else if (dp[n]!=-1)
        return dp[n];
    else
    {
        if (n==1)
            return dp[n]=solve(a,b,n-1,dp)+a[n-1]*b[n-1];
        else
            return dp[n]=max(solve(a,b,n-1,dp)+a[n-1]*b[n-1],solve(a,b,n-2,dp)+a[n-2]*(1-b[n-2])+a[n-1]*(1-b[n-1]));
    }
}
int main()
{
    vec a={4,3,2,1,5};
    vec b={0,1,0,1,0};
    vec dp(a.size()+1,-1);
    cout<<solve(a,b,a.size(),dp);
}
