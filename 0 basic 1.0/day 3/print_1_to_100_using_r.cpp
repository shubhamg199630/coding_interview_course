#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define vec(x) vector <x>
#define vecvec(x) vector<vector <x>>
#define pb push_back
#define F first
#define S second
#define pr(x,y) pair<x,y>
#define co(x) cout<<x
using namespace std;
void print_1_to_100(int n)
{
    if (n>100)        //1  // stopping condtion    // base condition
        return ;      //2
    else            //recursive part
    {

        print_1_to_100(n+1); //3
        cout<<n<<" ";        //4
    }
}


int main()
{
    print_1_to_100(1);
    cout<<"anshu";
}
