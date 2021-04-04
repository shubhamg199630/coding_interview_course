#include<bits/stdc++.h>         // new header file
using namespace std;
/*void swap_(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}*/
void reverse_array(vector <int> &a)
{
    //add code here
    int n=a.size();             // vector size
    int i=0,j=n-1;
    while (i<j)
    {
        swap(a[i],a[j]);
        //swap_(&a[i],&a[j]);
        i++;
        j--;
    }
}
int main()
{
    int n;
    cin>>n;
    vector <int> a(n);           // a vector on size n
    for (int i=0;i<n;i++)
        cin>>a[i];
    reverse_array(a);           // function calling
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
