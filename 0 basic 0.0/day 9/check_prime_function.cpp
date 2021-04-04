#include<iostream>
using namespace std;

bool check_prime(int n)
{
    if (n==1)
        return false;
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)         // it is n is divisible by i
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    cout<<check_prime(n);
}
