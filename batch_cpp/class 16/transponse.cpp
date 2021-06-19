
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3][3];
    int k=0;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            a[i][j]=k;
            k++;
        }
    }
    int b[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            b[i][j]=a[j][i];
    }

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
}
