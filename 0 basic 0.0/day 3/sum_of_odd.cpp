#include<iostream>
using namespace std;
int main()
{
    int sum=0;
    for (int i=1;i<=10;i++)
    {
        // not divisible by 2
        //1+3+5+7+9=25
        if (i%2==1)// condition for odd numbers
        {
            sum=sum+i;
        }
    }
    cout<<sum<<endl;
}
