#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;         // n is the size of array
    int a[n];           // array declaration
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;     // element to be search
    int flag=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==x)        // check whether a[i]
        {
            flag=1;
            break;
        }
    }
    cout<<flag<<endl;

}
