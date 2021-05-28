#include<bits/stdc++.h>
using namespace std;
void swap_(int &a,int &b) //pass by referance
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int x=10,y=20;
    cout<<x<<" "<<y<<endl;
    swap_(x,y);
    cout<<x<<" "<<y;
}
