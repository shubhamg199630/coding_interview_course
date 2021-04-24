#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int c=0,minusone=0,one=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]==1)
                one++;
            else if (a[i]==-1)
                minusone++;
            else if (a[i]==0)
                continue;
            else
                c++;
        }
        if ((c==0&&one>=1&&minusone>=2)||c<=1)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
}
