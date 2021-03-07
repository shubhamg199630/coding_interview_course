#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll power(ll a, ll n)
{
    //cout<<"power ("<<a<<" "<<n<<") "<<endl;
    if (n==0)
        return 1;
    else if (n==1)
        return a%mod;
    else
    {
        ll temp=power(a,n/2)%mod;
        if (n%2==0)     // n is even
            return (temp*temp)%mod;
        else
            return (temp*temp*(a%mod))%mod;
    }
}
int main()
{
    ll a=2;
    ll n=3;
    cout<<power(a,n);       // i am printing value from funtion
}
