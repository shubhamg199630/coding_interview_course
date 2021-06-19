#include <iostream>
using namespace std;
void swap(int *p,int *q)
    {
        int temp=*p;
        *p=*q+2;
        *q=10;
    }
int main()
{
    int x=10;
    int y=20;
    swap(&x,&y);

    cout<<x<<y;
}
