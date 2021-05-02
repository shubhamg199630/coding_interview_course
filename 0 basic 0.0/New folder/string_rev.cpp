#include<bits/stdc++.h>
using namespace std;
string string_rev(string s)
{
    int n=s.size();
    int i=0,j=n-1;
    while (i<j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
int main()
{
    string s="madam";
    string sr=string_rev(s);
    if (s==sr)
        cout<<"palindrome";
    else
        cout<<"Not palindrome";
   // cout<<s;
}
