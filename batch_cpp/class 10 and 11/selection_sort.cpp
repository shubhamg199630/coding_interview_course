#include<bits/stdc++.h>
using namespace std;
void print(vector <int> a)
{
    int n=a.size();
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selection_sort (vector <int> &a)
{
    int n=a.size();
    for (int i=0;i<n-1;i++)
    {
        int pos=0,mi=INT_MAX;
        for (int j=i;j<n;j++)
        {
            if (a[j]<mi)
            {
                mi=a[j];
                pos=j;
            }
        }
        swap(a[i],a[pos]);
        print(a);
    }
}

int main()
{
    vector <int> arr={4,6,5,3,2,8,1};
    selection_sort(arr);
    print(arr);
}
