#include<iostream>
using namespace std;
/*int main()
{
    int n;
    cin>>n;
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=n;i++)
            cout<<i;
        cout<<endl;
    }
}*/

/*int main()
{
    int n;
    cin>>n;
    for (int j=1;j<=n;j++)      // printing n times
    {
        for (int i=1;i<=n;i++)
            cout<<i+(n*(j-1));         // 1 + 5* (2-1)
        cout<<endl;
    }
}
*/


int main()
{
    int n;
    cin>>n;
    for (int j=1;j<=n;j++)
    {
        for (int i=1;i<=n;i++)
            cout<<j;
        cout<<endl;
    }
}
