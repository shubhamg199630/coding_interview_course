#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int i=0, j=n-1;
    while (i<j)
    {
        if (a[i]+a[j]==s)
            break;
        else if (a[i]+a[j]<s)       // sum is less i have to increase
            i++;
        else
            j--;
    }
    if (i<j)
        cout<<a[i]<<" "<<a[j];
    else
        cout<<-1;
}
