#include<bits/stdc++.h>
using namespace std;
void print(vector <int> &a)     // passing by referance
{
    for (int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
bool comparator(int x, int y)
{
    if (x>y)   //1 2 3    //x<y   true;
        return true;
    else
        return false;
}
int main()
{
    vector <int> a={3,2,5,4,6,1};
    print(a);
    sort(a.begin(),a.end());        // quick sort  //nlog(n)  // increasing order
    print(a);
    sort(a.begin(),a.end(), comparator);  // decreaing order
    print(a);
}


