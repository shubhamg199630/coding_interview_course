#include<bits/stdc++.h>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int sum(vector <int> a, int i, int total)
{
    if (i==a.size())
    return total;
    else
    {
        return sum(a,i+1,add(total,a[i]));
    }
}
int main()
{
    vector <int> a={1,2,3,4,5};
    cout<<sum(a,0,0);
}
