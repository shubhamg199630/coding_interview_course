#include<bits/stdc++.h>
using namespace std;
vector <int> reverse_vector(vector<int> a)
{
    // complete it;
    vector <int> rev;
    for (int i=a.size()-1;i>=0;i--)
    {
        rev.push_back(a[i]);
    }
    return rev;
}
bool check_vector_equal(vector <int> a, vector <int> b)
{
    // complete it
    /*if (a.size()!=b.size())
        return false;*/
    int n=a.size();
    for (int i=0;i<n;i++)
    {
        if (a[i]!=b[i])
            return false;
    }
    return true;
}
int main()
{
    vector <int> a={2,1,2};
    vector <int> b;
    b=reverse_vector(a);
    int flag=check_vector_equal(a,b);
    if (flag==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
