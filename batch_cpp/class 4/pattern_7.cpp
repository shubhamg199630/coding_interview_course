#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=n-1;
    for (int i=0;i<n;i++)
    {

        for (int j=0;j<2*n-1;j++)
        {
            if (j<c)
                cout<<" ";
            else if (j<2*n-1-c)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
        c=c-1;
    }
    c=1;
    for (int i=0;i<n-1;i++)
    {

        for (int j=0;j<2*n-1;j++)
        {
            if (j<c)
                cout<<" ";
            else if (j<2*n-1-c)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
        c=c+1;
    }
}
