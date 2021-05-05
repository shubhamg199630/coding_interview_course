#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        if (i%2==0)     // i is even
        {
            for (int j=0;j<n;j++)
                cout<<j+1;
        }
        else
        {
            for (int j=n-1;j>=0;j--)
                cout<<j+1;
        }
        cout<<endl;
    }
}
++
