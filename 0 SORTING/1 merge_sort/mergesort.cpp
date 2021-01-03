#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
void merge(int *a, int l , int mid, int r)
{
    int p[mid-l+1];
    int q[r-mid+2];
    p[mid-l]=q[r-mid+1]=INT_MAX;
    int x=0;
    for (int i=l;i<mid;i++)     //copying element to p
        p[x]=a[i],x++;
    x=0;
    for (int i=mid;i<=r;i++)    // copying element to q
        q[x]=a[i],x++;
    x=0;
    int i=0,j=0;
    for (int x=l;x<=r;x++)         // adding in correct order   in a
    {
        if (p[i]<=q[j])
            a[x]=p[i],i++;
        else
            a[x]=q[j],j++;
    }
}
void mergesort(int *a, int l, int r)
{
    if (l>=r)
        return ;
    else
    {
        int mid=(l+r+1)/2;          // +1 will be add to avoid infinite loop condition
        mergesort(a,l,mid-1);
        mergesort(a,mid,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n=6;
    int a[6]={4,3,2,1,5,6};
    mergesort(a,0,5);
    for (int i=0;i<6;i++)
        cout<<a[i]<<" ";
}
