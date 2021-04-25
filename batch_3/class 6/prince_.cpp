#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n,r;
        cin>>n>>r;;
        vector <ll> a(n);
        vector <ll> b(n);
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<n;i++)
            cin>>b[i];
        ll x=b[0],mx=b[0];
        for (int i=1;i<n;i++)
        {
            x=max(x-r*(a[i]-a[i-1]),(ll)0);
            x=x+b[i];
            mx=max(mx,x);
        }
        cout<<mx<<endl;
    }
}
