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

bool check_palindrome(string &s, int first , int last)
{
    // base condition
    cout<<"check_palindrome("<<first<<" "<<last<<")\n";
    if (first>=last)
        return true;
    else
    {
        if (s[first]!=s[last])      // not same // not palindrome
            return false;
        else
        {
            return check_palindrome(s,first+1, last-1);
        }
    }
}

int main()
{
    string s;
    cin>>s;         // input for user
    cout<<check_palindrome(s,0,s.size()-1);            //hello   0 and 4
}


