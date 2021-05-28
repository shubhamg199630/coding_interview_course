#include<bits/stdc++.h>
using namespace std;
void swap_(int &a,int &b) //pass by referance
{
    int temp=a;
    a=b;
    b=temp;
}
void print (vector<int> a)
{
    for (int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
}
void bubble_srt(vector <int> &a)
{
    for (int i=0;i<a.size()-1;i++)          // n-1 pass
    {
        for (int j=0;j<a.size()-1-i;j++)
        {
            if (a[j] >a[j+1])
                swap_(a[j],a[j+1]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    bubble_srt(a);
    print(a);
}
