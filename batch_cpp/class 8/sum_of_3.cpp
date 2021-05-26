#include<iostream>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    int hash_[10001]={0};       // all values will be zero
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        hash_[a[i]]=1;
    }
    int flag=0;
    for (int i=0;i<n;i++)
    {
        int first=a[i];
        for (int j=i+1;j<n;j++)
        {
            int second=a[j];
            if (hash_[s-first-second]==1)
            {
                cout<<first<<" "<<second<<" "<<s-first-second;
                flag=1;
                break;
            }
        }
        if (flag==1)
            break;
    }
    if (flag==0)
        cout<<-1;
}
