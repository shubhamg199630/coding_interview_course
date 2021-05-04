#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n!=0)   //0!=0        true
    {
        cout<<n%10;
        n=n/10;
    }
}
