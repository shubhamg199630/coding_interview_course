#include<bits/stdc++.h>
using namespace std;
void zero_front_last(vector <int> &arr)
{
    int n=arr.size();
    vector <int> a;
    vector <int> b;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==0)
            a.push_back(arr[i]);
        else
            b.push_back(arr[i]);
    }
    if (a.size()<b.size())      // zero are less
    {
        int i=0;
        for (;i<a.size();i++)
        {
            arr[i]=a[i];
        }
        for (int j=0;j<b.size();j++)
        {
            arr[i]=b[j];
            i++;
        }
    }
    else
    {
        int i=0;
        for (;i<b.size();i++)
        {
            arr[i]=b[i];
        }
        for (int j=0;j<a.size();j++)
        {
            arr[i]=a[j];
            i++;
        }
    }
}
int main()
{
    vector<int> arr={0,10,20,0,0};
    zero_front_last(arr);
    for (int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";

}
