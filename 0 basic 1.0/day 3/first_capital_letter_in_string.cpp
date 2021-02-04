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
char find_first(string s, int n)
{
    if (n>=s.size())        // your string is over
    {
        return '0';
    }
    else if ((int)s[n]>=65&&(int)s[n]<=90)           //base case // stopping
    {
        return s[n];
    }
    else
    {       // current char is not capital
        return find_first(s, n+1);
    }
}

int main()
{
    string s;
    cin>>s;     // user input
    cout<<find_first(s,0);
}
