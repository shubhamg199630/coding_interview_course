#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x
using namespace std;
void reverse(vec(int) &a)
{
    int i=0,j=a.size()-1;
    while (i<j)
    {
        swap(a[i],a[j]);
        i++;
        j--;
    }
}
void solve(vec(int) &a)
{
    stack <int> s;
    vec(int) ans;
    for (int i=0;i<a.size();i++)
    {
        while (!s.empty()&&s.top()>=a[i])
            s.pop();
        if (s.empty())
            ans.pb(-1);
        else
            ans.pb(s.top());
        s.push(a[i]);
    }
    reverse(ans);
    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    vec(int) a;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.pb(x);
    }
    reverse(a);
    solve(a);
}
