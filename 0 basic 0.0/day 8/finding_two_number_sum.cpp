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
    int s;
    cin>>s;
    int x=-1,y=-1,z=-1;
    for (int i=0;i<n-2;i++)
    {
        x=a[i];
        for (int j=i+1;j<n-1;j++)
        {
            y=a[j];
            for (int k=j+1;k<n;k++)
            {
                z=a[k];
                if (x+y+z==s)
                {
                    break;
                }
            }
            if (x+y+z==s)
            break;
        }
        if (x+y+z==s)
            break;
    }
    if (x+y+z==s)
        cout<<x<<" "<<y<<" "<<z<<endl;
    else
        cout<<"NOT FOUnd";
}
