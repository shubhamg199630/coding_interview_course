#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int flag=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==10)       // 10 is present i  array
        {
            flag=1;
        }
    }
    if (flag==1)
        cout<<"true";
    else
        cout<<"false";
}
