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
struct node
{
    int data;
    struct node *next;
};
node * create_node(int x)
{
    node* p=(node *)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    return p;
}
node* push(node*top ,int x)
{
    node *p=create_node(x);
    if (p==NULL)       // overflow
    {
        cout<<"overflow" ;
        exit (0);
    }
    else
    {

        p->next=top;
        top=p;
        return top;
    }
}
node* pop(node *top)
{

    if (top==NULL)       // underflow
    {
        cout<<"underflow" ;
        exit (0);
    }
    else
    {
        node *p=top;
        top=top->next;
        free(p);
        p=NULL;
        return top;
    }
}
int main()
{

    int n;
    cin>>n;         // no of opearation
    node *top=NULL;
    while (n!=0)
    {
        string s;
        cin>>s;
        if (s=="push")
        {
           // cout<<"asasa";
            int x;
            cin>>x;
            top=push(top,x);
        }
        else
        {
            top=pop(top);
        }
        node*p=top;
        while (p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
