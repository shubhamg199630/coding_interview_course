#include<bits/stdc++.h>
using namespace std;

/*char a[2][4]={'2','a','b','c','3', 'd','e','f'};*/

bool check(string s, string t)
{
    int c=0,one=-1,two=-1;
    if (s.size()!=t.size())
        return 0;
    for (int i=0; i<s.size(); i++)
    {
        c++;
    }
    if(c>2)
        return 0;
    else
        return 1;
}
int numSimilarGroups(vector<string>& strs)
{
    map<int, vector <string>> hash;
    if (strs.size()==0)
        return 0;
    vector <string> temp;
    temp.push_back(strs[0]);
    hash.insert({0,temp});
    for (int i=1; i<strs.size(); i++)
    {
        int flag=0;
        string q=strs[i];
        for (auto itr=hash.begin(); itr!=hash.end(); itr++)
        {
            for (int j=0; j<itr->second.size(); j++)
            {
                string p=itr->second[j];
                if (check(p,q))
                {
                    flag=1;
                    itr->second.push_back(p);
                    break;
                }
            }
        }
        if (flag==0)
        {
            vector <string> temp1;
            temp1.push_back(strs[i]);
            hash.insert({hash.size()-1,temp1});
        }
    }
    return hash.size();
}
int main()
{
    vector <string> s={"star","rats", "tars" };
    cout<<check("stars", "rats");
    cout<<numSimilarGroups(s);
}
