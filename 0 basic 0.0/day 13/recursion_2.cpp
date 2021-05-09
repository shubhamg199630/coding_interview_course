#include<bits/stdc++.h>
using namespace std;
void print(vector <int> a, int i)
{
    //cout<<"print( "<<i<< " ); "<<endl;;
    if (i<0)
        return ;
    else
    {
        cout<<a[i]<<" ";
        print(a,i-1);
    }
}
int main()
{
    vector <int> a={1,2,3,4,5};
    print(a, a.size()-1);
}

