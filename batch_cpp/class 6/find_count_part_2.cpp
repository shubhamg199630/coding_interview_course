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
    int b[n]= {0};
    for (int i=0; i<n; i++)
    {
        int c=1;
        if (b[i]==0)            // element i is unproce
        {
            for (int j=i+1; j<n; j++)
            {
                if (a[i]==a[j])
                {
                    c++;
                    b[j]=1;
                }
            }
            cout<<a[i]<<" comes= "<<c<<endl;
        }
    }
}
