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
    // find missing number
    int b[n+2]={0};
    for (int i=0;i<n;i++)
    {
        int x=a[i];
        b[x]=1;
    }
    int ans=-1;
    for (int i=1;i<=n+1;i++)
    {
        if (b[i]==0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans;
}
