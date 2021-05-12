#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int i=0,j=n-1;
    int flag=1;
    while(i<j)
    {
        if (a[i]!=a[j])
            flag=0;
        i++;
        j--;
    }
    if (flag==1)
        cout<<"yes";
    else
        cout<<"no";
}
