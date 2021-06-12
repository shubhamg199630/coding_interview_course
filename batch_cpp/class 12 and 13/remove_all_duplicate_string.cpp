#include<bits/stdc++.h>
using namespace std;
string remove_duplicate(string s)
{
    int a[26]={0};
    string ans;
    for (int i=0;i<s.size();i++)
    {
        int x=(int)s[i]-97;         // 0 to 25
        if (a[x]==0)
        {
            ans=ans+s[i];
            a[x]=1;
        }
    }
    return ans;
}
string add_duplicate(string s)
{
    int a[26]={0};
    string ans;
    for (int i=0;i<s.size();i++)
    {
        int x=(int)s[i]-97;         // 0 to 25
        if (a[x]==0)
        {
            a[x]=1;
        }
        else
        {
            if (a[x]==1)
                ans=ans+s[i];
            a[x]++;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    s=add_duplicate(s);
    cout<<s;
}
