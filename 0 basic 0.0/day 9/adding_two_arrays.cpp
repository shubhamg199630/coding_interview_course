#include<bits/stdc++.h>
using namespace std;
vector <int> add_two_array(vector <int> &a,vector <int> &b)
{
    int n=a.size();
    vector <int> ans(n);
    for (int i=0;i<n;i++)
    {
        ans[i]=a[i]+b[i];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    vector <int> b(n);
    for (int i=0;i<n;i++)
        cin>>b[i];
    vector <int> ans;
    ans=add_two_array(a,b);
    for (int i=0;i<n;i++)
        cout<<ans[i]<<" ";

}
