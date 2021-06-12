#include<bits/stdc++.h>
using namespace std;
int sum=0;
char print(string a, int i)
{
   // cout<<"print("<<i<<")"<<endl;
    if (i==a.size())
        return '0';
    else
    {
        //sum=sum+a[i];
        if (a[i]>='A' &&a[i]<='Z')
            return a[i];
        return print(a,i+1);
    }
}
char temp='0';
char print_last(string a, int i)
{
    if (i==a.size())
        return temp;
    else
    {
        if (a[i]>='A' &&a[i]<='Z')
            temp=a[i];
        return print_last(a,i+1);
    }
}
int main()
{
    string a="sasAfefedfedfBsdsdsFd";
    cout<<print_last(a,0);
}
