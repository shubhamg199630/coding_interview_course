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
char curr_cap_='0';
char find_last(string s, int n)
{
    if (n>=s.size())        // your string is over
    {
        return curr_cap;
    }
    else
    {
        if ((int)s[n]>=65&&(int)s[n]<=90)// capital
            curr_cap=s[n];
        return find_last(s,n+1);
    }
}
int main()
{
    string s;
    cin>>s;     // user input
    cout<<find_second(s,0);
}
