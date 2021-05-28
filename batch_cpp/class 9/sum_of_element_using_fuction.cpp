#include<bits/stdc++.h>
using namespace std;
int sum_of_array(vector <int> a);
int find_max(vector <int> a)
{
    int mx=-1;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]>mx)
            mx=a[i];
    }
    return mx;
}

int main()
{
    //int a[n];
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    //cout<<sum_of_array(a);
    cout<<find_max(a);
}
int sum_of_array(vector <int> a)
{
    int n=a.size();
    int sum=0;
    for (int i=0;i<n;i++)
        sum+=a[i];
    return sum;
}

