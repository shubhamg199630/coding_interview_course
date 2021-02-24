#include<bits/stdc++.h>
using namespace std;
int power(int a, int n)
{
    if (n==0)
        return 1;       //stopping condition
    else
        return power(a,n-1)*a;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<power(a,n);
}
