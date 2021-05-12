#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int b[n];
    for (int i=0;i<n;i++)
    {
        b[n-1-i]=a[i];      // coping in reverse
    }
    int flag=1;
    for (int i=0;i<n;i++)
    {
        if (a[i]!=b[i])
            flag=0;
    }
    if (flag==1)
        cout<<"yes";
    else
        cout<<"no";
}
