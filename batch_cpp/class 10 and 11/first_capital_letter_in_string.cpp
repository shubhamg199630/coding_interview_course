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
int count_=0;
char find_second(string s, int n)
{
    if (n>=s.size())        // your string is over
    {
        return '0';
    }
    else
    {
        if ((int)s[n]>=65&&(int)s[n]<=90&&count_==1)// capital and count=1
                return s[n];
        else if ((int)s[n]>=65&&(int)s[n]<=90)
            count_++;
        return find_second(s, n+1);
    }
}

int main()
{
    string s;
    cin>>s;     // user input
    cout<<find_second(s,0);
}
