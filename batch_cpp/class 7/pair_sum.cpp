#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int flag=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]+a[j]==s)
            {
                cout<<a[i]<<" "<<a[j]<<endl;
                flag=1;
                break;
            }
        }
        if (flag==1)
            break;
    }
}
