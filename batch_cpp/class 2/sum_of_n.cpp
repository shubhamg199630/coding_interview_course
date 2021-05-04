#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i=0;i<n;i++)          // 0 to n-1 =
    {
        int x;
        cin>>x;
        sum=sum+x;
    }
    cout<<sum;
}
