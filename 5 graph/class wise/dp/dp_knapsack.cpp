#include<bits/stdc++.h>
using namespace std;
vector <vector <int>> dp(1001,vector <int> (1001, -1));
int knapsack(int n, vector <int> &profit, vector <int> &weight, int m)
{
    if (n==0)       //no element left
        return 0;
    else if (dp[n][m]!=-1)
        return dp[n][m];
    else
    {
        if (weight[n-1]<=m)
        {
            dp[n][m]=max(knapsack(n-1,profit, weight, m-weight[n-1])+profit[n-1]
                ,knapsack(n-1,profit,weight,m));
        }
        else
            dp[n][m]=knapsack(n-1,profit,weight,m);
        return dp[n][m];

    }
}

int main()
{
    vector <int> profit={ 60, 100, 120 };
    vector <int> weight={ 10, 20, 30 };
    int m=0;
    cout<<knapsack(profit.size(),profit,weight,m);

}
