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

// sum of even in total
int even_total(vector <int> a)
{
    int t=0;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]%2==0)      // condition for even
            t+=a[i];
    }
    return t;
}


int main()
{
    int n;
    cin>>n;
    vector <int> a; // a is a vector of integer
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<even_total(a);
}

