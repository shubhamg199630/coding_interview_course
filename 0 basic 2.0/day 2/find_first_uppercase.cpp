#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x<<endl
using namespace std;

char find_uppercase(string &s, int curr)
{
    // base case
    if (s.size()==curr)
        return '0';
    else
    {
        if (s[curr]>=65&&s[curr]<=90)       // uppercase
            return s[curr];
        else            // not uppercase
            return find_uppercase(s,curr+1);
    }
}
int main()
{
    string s;
    cin>>s;         // input for user
    cout<<find_uppercase(s,0);            //hello   0 and 4
}


