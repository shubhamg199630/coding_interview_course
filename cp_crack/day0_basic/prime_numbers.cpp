#include<bits/stdc++.h>
using namespace std;
int prime(int n)
{
    if (n==1)
        return 0;
    for (int i=2;i<n;i++)
    {
        if (n%i==0)     // divisible
            return 0;
    }
    return 1;
}
int main()
{
   int n;
   cin>>n;
   int x=prime(n);
   if (x==1)
        cout<<"PRime";
   else
    cout<<" NOT Prime";

}
