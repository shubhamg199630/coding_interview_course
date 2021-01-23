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
    for (int k=0;k<10;k++)   // 0 1 2 3 4 5 6 7 8 9 10
    {
        int c=0;
        for (int i=0;i<n;i++)//n  n n n n n n n n n n = 10 n
        {
            if (a[i]==k)
                c++;     //c=c+1;
        }
        cout<<k<<" comes"<<c<<"times"<<"\n";
    }
}
// TLE  = 1 sec
// 10 * 5 =50
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
