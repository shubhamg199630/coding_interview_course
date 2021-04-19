#include<bits/stdc++.h>
using namespace std;
vector <int> sum_vector(vector <int> a, vector <int> b)
{
    int n=a.size();
    vector <int> c;   // c has zero size
    for (int i=0;i<n;i++)
    {
        c.push_back(a[i]+b[i]);
    }
    c.pop_back();
    c.pop_back();
    return c;
}
int main()
{
    vector<int> a={1,2,3,4,5,6};
    vector<int> b={3,3,3,3,3,3};
    vector <int> ans;
    ans=sum_vector(a,b);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

}
