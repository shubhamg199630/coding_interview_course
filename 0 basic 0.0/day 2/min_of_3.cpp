#include<iostream>
using namespace std;
int main()
{
    int a=100,b=20,c=30;
    if (a<b&&a<c)
    {
        cout<<"a";
    }
    else if (b<a&&b<c)
    {
        cout<<"b";
    }
    else
    {
        cout<<"c";
    }
}
