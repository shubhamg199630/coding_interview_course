#include<bits/stdc++.h>
using namespace std;
int n=15;
int k=11;
void print(vector <int> &a)
{
    for (int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void print_all_combination(vector <int> &a, int curr)
{
    if (a.size()==k)
    {
        print(a);
    }
    else
    {
        for (int i=curr+1;i<=n;i++)
        {
            a.push_back(i);
            print_all_combination(a,i);
            a.pop_back();
        }
    }
}
int main()
{
    vector <int> a;
    print_all_combination(a,0);

}
