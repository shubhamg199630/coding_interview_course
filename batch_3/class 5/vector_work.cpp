#include<bits/stdc++.h>
using namespace std;
void print (vector <pair<string, int>> &a)
{
    for (int i=0;i<a.size();i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
}
bool comparator(pair<string,int> x, pair<string,int> y)
{
    if (x.second>y.second)
        return true;
    else
        return false;
}
int main()
{
    vector <pair<string,int>> a;
    //cout<<a.size()<<endl;       // zero
    a.push_back({"vijay",40});
    a.push_back({"raj", 30});
    a.push_back({"rahul",50});
    //a.pop_back();
    //cout<<a.size()<<endl;

    //sort()
    //print(a);
    sort(a.begin(),a.end(),comparator);
    print(a);
}
