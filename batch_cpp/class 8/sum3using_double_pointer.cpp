#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int flag=0;
    for (int k=0; k<=n-3; k++)
    {
        int i=k+1, j=n-1;
        while (i<j)
        {
            if (a[k]+a[i]+a[j]==s)
                break;
            else if (a[k]+a[i]+a[j]<s)       // sum is less i have to increase
                i++;
            else
                j--;
        }
        if (i<j)
        {
            cout<<a[k]<<" "<<a[i]<<" "<<a[j];
            flag=1;
            break;
        }
    }
    if (flag==0)
        cout<<-1;
}
