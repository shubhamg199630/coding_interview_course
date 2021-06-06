#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector <vector <char>> a(4,vector <char> (9,' ' ));
    a[2][0]='*';
    a[1][1]='*';
    a[0][2]='*';
    a[1][3]='*';
    a[2][4]='*';
    a[3][5]='*';
    a[2][6]='*';
    a[1][7]='*';
    a[0][8]='*';
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<9;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}
