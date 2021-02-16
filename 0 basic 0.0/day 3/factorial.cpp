#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;  //n=3

    int fac=1;
    for (int i=1;i<=n;i++)
    {
        fac=fac*i;
    }
    cout<<fac;
}
