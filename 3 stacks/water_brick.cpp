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
int solve(vec(int) &a)
{
    int n=a.size();
    int left[n];
    int right[n];
    int mx=0;
    for (int i=0;i<n;i++)
    {
        left[i]=mx;
        mx=max(a[i],mx);
      //  cout<<left[i]<<" ";
    }
    //cout<<endl;
    mx=0;
    for (int i=n-1;i>=0;i--)
    {
        right[i]=mx;
        mx=max(a[i],mx);
    }
    /*for (int i=0;i<n;i++)
        cout<<right[i]<<" ";
    cout<<endl;*/
    int c=0;
    for (int i=0;i<n;i++)
    {
        int x=min(left[i],right[i])-a[i];
        if (x>0)
            c=c+x;
        //cout<<x<<" ";
    }
    //cout<<endl;
    return c;
}

int main()
{
    int n;
    cin>>n;
    vec(int) a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(x);
    }
    cout<<solve(a);
}
