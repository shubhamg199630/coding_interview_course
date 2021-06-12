#include<bits/stdc++.h>
using namespace std;
void print(string s, int i, int j)
{
    for (int k=i;k<=j;k++)
    {
        cout<<s[k];
    }
    cout<<endl;
}
void print_substring(string s)
{
    for (int i=0;i<s.size();i++)
    {
        for (int j=i;j<s.size();j++)
        {
            print(s,i,j);
        }
    }
}
int main()
{
    string s="abcd";
    print_substring(s);
}
