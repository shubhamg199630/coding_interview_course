#include<bits/stdc++.h>
using namespace std;

void print(int n)
{
    for (int i=0;i<n;i++)
    {
        //sorted order
        for (int j=0;j<n;j++)
        {
            if (j<=i)
                cout<<j+1;
            else
                cout<<" ";
        }
        // reverse order
        for (int j=n-1;j>=0;j--)
        {
            if (j<=i)
                cout<<j+1;
            else
                cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    print(n);
}
