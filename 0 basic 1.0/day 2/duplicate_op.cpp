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

int find_duplicate(vector <int> a)
{
    int n=a.size();
    vector <int> vis(1000000,0);
    for (int i=0;i<n;i++)
    {
        if (vis[a[i]]==1)
            return a[i];
        else
            vis[a[i]]++;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;         // n is number of element in array;
    vector <int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);     // element added
    }
    cout<<find_duplicate(a);
}
