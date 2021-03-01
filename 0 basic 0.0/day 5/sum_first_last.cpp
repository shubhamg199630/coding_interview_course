#include<iostream>
using namespace std;
/*int main()
{
    int n;
    cin>>n;
    int sum=0;
    for (;n>=10;n=n/10 )
    {
        sum=sum+n%10;
    }
    sum=sum+n;
    cout<<sum<<endl;
}*/
/*int main()
{
    for (;1;)
    {
        int n;
        cin>>n;
        if (n==42)
            break;      //exit this current loop
        else
            cout<<n<<endl;
    }

}*/




int main()
{
    int n;
    cin>>n;
    for (;n!=42;)
    {
        cout<<n<<endl;
        cin>>n;
    }
}
