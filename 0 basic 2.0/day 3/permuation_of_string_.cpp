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
void permutation(string s, int curr)
{
    if (curr==s.size())         // base condition to stop this code
    {
        cout<<s<<endl;
        return ;
    }
    else
    {
        for (int i=curr;i<s.size();i++)
        {
            swap(s[i],s[curr]);    // for calling you swapping
            permutation(s,curr+1);
            swap(s[i],s[curr]);
        }
    }
}
int main()
{
    string s="ABCD";
    permutation(s,0);
}
