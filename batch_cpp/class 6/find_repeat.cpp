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
    //array is sorted
    int last_print=-1;
    for (int i=0;i<n-1;i++)
    {
        if (a[i]==a[i+1]&&a[i]!=last_print)       // both are matching
        {
            cout<<a[i]<<" ";
            last_print=a[i];
        }
    }

}
