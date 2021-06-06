
#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n)
{
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}
int main()
{
    cout<<check_prime(13);
}
