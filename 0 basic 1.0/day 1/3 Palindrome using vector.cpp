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

bool palindrome_check(vector <int > a)
{
    int n=a.size();
    vector <int> b;
    for (int i=n-1;i>=0;i--)
        b.push_back(a[i]);
    if (a==b)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin>>n;
    vector <int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<palindrome_check(a);
}
