#include<bits/stdc++.h>
using namespace std;
string reverse_string (string s)
{
    string temp;
    for (int i=s.size()-1;i>=0;i--)
    {
        temp=temp+s[i];
    }
    return temp;
}
bool check_palindrome(string s)
{
    string s_rev=reverse_string(s);
    if (s_rev==s)
        return true;
    return false;
}
void convert_into_capital(char &a)
{
    if (a>=97)
        a=(char)(a-32);
}
bool check_palindrome_without_rev(string s)
{
    int i=0,j=s.size()-1;
    while (i<j)
    {
        convert_into_capital(s[i]);
        convert_into_capital(s[j]);
        if (s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string s="mAdaM";
    //cout<<check_palindrome(s);
    cout<<check_palindrome_without_rev(s);
}
