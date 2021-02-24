#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll a, ll n)
{
    //cout<<a<<" "<<n<<endl;
    if (n==0)
        return 1;
    else if (n==1)       // base or stopping condtion
        return a;
    else
    {
        ll x=power(a,n/2);
        if (n%2==0)     //even number
            return x*x;
        else
            return x*x*a;
        //return (power(a,n/2)*power(a,n/2));
    }
}
int main()
{
    ll a,n;
    cin>>a>>n;
    cout<<power(a,n);
}
