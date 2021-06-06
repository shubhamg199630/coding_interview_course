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
void selection_sort_(vector <int> &a)
{
    int n=a.size();
    for (int i=0;i<n-1;i++)         // for every pass
    {
        int mi=INT_MAX, pos=-1;
        for (int j=i;j<n;j++)
        {
            if (a[j]<mi)
            {
                mi=a[j];
                pos=j;
            }
        }
        swap(a[i], a[pos]);
        cout<< "pass "<<i+1<<": ";
        print(a);
    }
}
int main()
{
    vector <int> a={4,5,2,7,3,6,8,1};
    selection_sort_(a);
    print(a);
}
