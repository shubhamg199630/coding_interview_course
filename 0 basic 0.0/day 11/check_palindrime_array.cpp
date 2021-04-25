#include<bits/stdc++.h>
using namespace std;
bool check_palindrome(vector <int> &a)
{
    int n=a.size();
    int i=0,j=n-1;
    while (i<j)
    {
        if (a[i]!=a[j])
            return false;
        i=i+1;
        j=j-1;
    }
    return true;
}
int main()
{
    vector <int> a={10,20,30,20,10};
    cout<<check_palindrome(a);
}
