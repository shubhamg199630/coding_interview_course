#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // print pattern
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (j<=i)       // to print number
                cout<<j+1;
            else
                cout<<" ";
        }
        for (int j=n-1;j>=0;j--)
        {
            if (j<=i)       // to print number
                cout<<j+1;
            else
                cout<<" ";
        }
        cout<<endl;
    }
}
