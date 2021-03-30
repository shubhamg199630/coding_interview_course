#include<bits/stdc++.h>     // contains all library of cpp
using namespace std;
void rev(int n)
{
    while (n!=0)
    {
        int last=n%10;          // getting last digit
        cout<<last;
        n=n/10;             // revoming last digit from number
    }
}
bool check_prime(int n)     //
{
    if (n==1)
        return 0;
    int p=1;        // intially number is prime
    for (int i=2;i*i<=n;i++)         // O(root(n))
    {
        if (n%i==0)     // divisible condition
        {
            p=0;
            break;
        }
    }
    return p;
}
void pattern (int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
            cout<<j+1;
        cout<<endl;
    }
}
int linear_search(vector <int> &a, int x)   //O(n)
{
    int n=a.size();// n os number of element in vector
    for (int i=0;i<n;i++)
    {
        if (a[i]==x)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;         // scanf();
    vector <int> a(n);      // list python
    //int a[n];       // array
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    /*
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
    }*/

    //rev(n);

    //cout<<check_prime(n);
    // pattern(n);
    cout<<linear_search(a, 2);
}
