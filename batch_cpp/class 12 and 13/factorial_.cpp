
#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    cout<<"factorial("<< n<<")"<<endl;
    if (n==0||n==1)
    {
        return 1;
    }
    else
    {
        return factorial(n-1)*n;
    }
}
int main()
{
    cout<<" "<<factorial(5);
}
