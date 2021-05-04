#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int even_count=0,odd_count=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x%2==0)  // even
            even_count++;
        else
            odd_count++;
    }
    cout<<even_count<<" "<<odd_count;
}
