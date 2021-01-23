#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x<<endl
using namespace std;

int min_in_array(int a[],int n)     //function
{
    int mi=a[0];        // first element is minimum/
    for (int i=1;i<n;i++)
    {
        if (a[i]<mi)        // = will not make any diff
            mi=a[i];
    }
    return mi;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];          // inserting all element
    }
    cout<<min_in_array(a,n);

}

