#include<bits/stdc++.h>

using namespace std;
int lcs(string &s1, string &s2, int m ,int n,vector <vector<int>> &dp)
{
    if (m==0||n==0)
        return dp[m][n]=0;
    else if (dp[m][n]!=-1)
        return dp[m][n];
    else
    {
        int temp=0;
        temp=max(lcs(s1,s2,m-1,n,dp),lcs(s1,s2,m,n-1,dp));
        if (s1[m-1]==s2[n-1])
            temp=max(lcs(s1,s2,m-1,n-1,dp)+1,temp);
        return dp[m][n]=temp;
    }
}
//L(“AGGTAB”, “GXTXAYB”)
string s1="AGGTAB";
asdewqedsa    asdeedsa
string s2="GXTXAYB";
int m=s1.size(),n=s2.size();
print(vector <vector<int>> &dp)
{
    for (int i=0;i<dp.size();i++)
    {
        for (int j=0;j<dp[0].size();j++)
        {

                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
string reverse_(string &s, int n)
{
    int i=0,j=n-1;
    while (i<=j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
string_lcs(vector <vector<int>> &dp)
{
    int i=m;
    int j=n;
    string s;
    while (i!=0&&j!=0)
    {
        if (s1[i-1]==s2[j-1])      // match
        {
            s=s+s1[i-1];
            i--;
            j--;
        }
        else if (dp[i][j]==dp[i][j-1])
        {
            j--;
        }
        else
            i--;
    }
    //cout<<s;
    s=reverse_(s,s.size());
    cout<<s<<endl;
}
int main()
{


    vector <vector<int>> dp(m+1,vector <int> (n+1,-1));
    cout<<lcs(s1,s2,s1.size(),s2.size(),dp);
    cout<<endl;
    print(dp);
    string_lcs(dp);
}
