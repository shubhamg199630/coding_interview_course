#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];      // a is array of size 10 which will store integers
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    //int mx=a[0];
    /*for (int i=1;i<4;i++)
    {
        if (a[i]>mx)
            mx=a[i];
    }
    cout<<mx;
    */
    //for number of zero in array
    /*int c=0;
    for (int i=0;i<4;i++)
    {
        if (a[i]==0)
            c++;

    }
    cout<<c;
    */
    int sum_odd=0;
    for (int i=1;i<n;i=i+2)
    {
            sum_odd=sum_odd+a[i];
    }
    cout<<sum_odd;
}
