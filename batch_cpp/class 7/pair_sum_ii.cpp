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
    int b[s+1]={0};
    for (int i=0;i<n;i++)
    {
        int x=a[i];
        if (x>s)        // igonore x greater then s
            continue;
        int find_=s-x;    //15-3;
        if (b[find_]==1)
        {
            cout<<find_<<" "<<x<<endl;
            break;
        }
        b[x]=1;
    }
}
