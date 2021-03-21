#include<iostream>
#include<algorithm>
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
    sort(a,a+n);
    int c=1;
    for (int i=0;i<n-1;i++)
    {
        if (a[i]==a[i+1])
            c++;
        else
        {
            cout<<a[i]<<"-->"<<c<<endl;
            c=1;
        }
    }
    cout<<a[n-1]<<"-->"<<c<<endl;
}
