#include<bits/stdc++.h>
using namespace std;
bool match(string s, int i, string old)
{
    for (int j=0;j<old.size();j++,i++)
    {
        if (s[i]!=old[j])
            return false;
    }
    return true;
}
void replace_(string &s, int i, string new_)
{
    for (int j=0;j<new_.size();j++,i++)
    {
        s[i]=new_[j];
    }
}
int main()
{
    string s="ratcatbatmathelloratcat";
    string old="rat";
    string new_="cat";
    for (int i=0;i<s.size();i++)
    {
        if (match(s,i,old)==true)       //
        {
            replace_(s,i,new_);
            i=i+new_.size()-1;
        }
    }
    cout<<s;
}
