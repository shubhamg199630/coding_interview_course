#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
    vector <int> a(26,0);
    string temp;
    for (int i=0;i<s.size();i++)
    {
        char ch=s[i];
        int val=(int)s[i]-97;
        if (a[val]==0)
        {
            temp=temp+ch;
            a[val]=1;
        }
    }
    return temp;
}
int main()
{
    string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaabdsaaaaaaaaaaa";
    cout<<solve(s);
}
