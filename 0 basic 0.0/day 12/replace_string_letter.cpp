#include<bits/stdc++.h>
using namespace std;
string solve(string s)
{
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='a')
            s[i]='b';
        else if (s[i]=='z')
            s[i]='y';
    }
    return s;
}
int main()
{
    string s="ababababayz";
    cout<<solve(s);
}
