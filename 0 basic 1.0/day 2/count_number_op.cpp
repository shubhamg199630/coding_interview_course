#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x
using namespace std;

void number_count(vector <int> a)
{
    int n=a.size();
    vector <int> count(10,0);
    for (int i=0;i<n;i++)
        count[a[i]]++;


    for (int k=0;k<10;k++)
    {
        cout<<k<<" comes"<<count[k]<<"times"<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;         // n is number of element in array;
    vector <int> a;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);     // element added
    }
    number_count(a);
}
