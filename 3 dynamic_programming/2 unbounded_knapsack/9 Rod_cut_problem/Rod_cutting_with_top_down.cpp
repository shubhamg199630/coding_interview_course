#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int knapsack(int profit[],int length[],int n,int m)
{
	//cout<<"sum_of_subset("<<sum<<","<<curr<<")\n";
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (length[i-1]<=j)
				dp[i][j]=max(dp[i-1][j],dp[i][j-length[i-1]]+profit[i-1]);		// diff between knapsack and unbounded knapsack
			else 
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][m];
}
void intialization_of_dp()
{
	memset(dp,-1,sizeof(dp));
	for (int i=0;i<=1000;i++)
	{
		for (int j=0;j<=1000;j++)
		{
			if (j==0||i==0)
				dp[i][j]=0;
		}
	}
}
void printdp(int n, int sum)
{
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=sum;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n;
	n=5;
	int weight[]={40,20,100,10,300};int length[]={1,2,3,4,5};int m=10; 				//m=capacity of bag
	intialization_of_dp();
	cout<<knapsack(val,weight,n,m)<<endl;
	//printdp(n,m);
}
