#include<bits/stdc++.h>
using namespace std;
void print_permutation(string s, int curr)
{
    // add code here
    cout<<"print_permutation "<<curr<<endl;
    if (curr==s.size())
    {
        //cout<<s<<endl;
        return ;
    }
    else
    {
        for (int i=curr;i<s.size();i++)
        {                          //  abc
            swap(s[curr],s[i]);    // bac
            print_permutation(s,curr+1);
            swap(s[curr],s[i]);   // bac    ->abc
        }
    }
}
int main()
{
    string s="abc";
    print_permutation(s,0);
}
