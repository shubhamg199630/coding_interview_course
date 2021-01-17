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

#include <iostream>

using namespace std;

string solve(string &s1, string &s2)
{
    int a1[26]={0};  // all a1 values are zero
    int a2[26]={0};
    for (int i=0;i<s1.size();i++)
    {
        int x=(int)s1[i]-97;
        a1[x]++;
    }
    for (int i=0;i<s2.size();i++)
    {
        int x=(int)s2[i]-97;
        a2[x]++;
    }
    string s3;
    for (int i=0;i<26;i++)
    {
        int x=min(a1[i],a2[i]);
        for (int j=0;j<x;j++)
            s3.push_back((char)(i+97));
    }
    return s3;

}

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<solve(s1,s2);
}
