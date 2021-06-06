#include<bits/stdc++.h>
using namespace std;
void print(vector <int> a)
{
    for (int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort_(vector <int> &a)
{
    int n=a.size();
    for (int i=0;i<n-1;i++)         // for every pass
    {
        for (int j=0;j<n-1-i;j++)
        {
            if (a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
       // cout<< "pass "<<i+1<<": ";
        //print(a);
    }
}
int main()
{
    vector <int> a={4,5,2,7,3,6,8,1};
    bubble_sort_(a);
    print(a);
}
