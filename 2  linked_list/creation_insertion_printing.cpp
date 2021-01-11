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


struct node         // struct data structure for linked list creation
{
    int val;
    struct node *next;
};
struct node * createnode(int v)         // function for creating new node and return pointer of that node.
{
    struct node *ptr= (struct node * ) malloc(sizeof(struct node ));
    ptr->val=v;
    ptr->next=NULL;
    return ptr;
};

void print(struct node * head)          // function for printing the list
{

    while (head!=NULL )
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}
void print_last_2(struct node * head)           // function to print if list has size>2 then only works
{
    struct node *p=NULL;
    while (head!=NULL)
    {

        if (head->next==NULL)
        {
            cout<<"LAST= "<<head->val<<endl;
            cout<<"2nd LAst= "<<p->val;
        }
        p=head;
        head=head->next;
    }
}
void find_x( node * head, int x)        // function to print address of x if present
{
    while (head)        //0(N)
    {
        if (head->val==x)
            cout<<head;
        head=head->next;
    }
}
node* insertatlast(node * head,int x)       // insertion at last
{
    node *root=head;        // copying head value
    node * p= createnode(x);        // node create
    if (head==NULL)     // if head is NULL
        return p;
    while (head->next!=NULL)   //0->next    // segmentation;
    {
        head=head->next;
    }
    head->next=p;
    return root;
}
node* insert_at_k(node *head, int x, int k)     // inserting element at kth place in linked list
{
    node * p= createnode(x);
    if (k==1)
    {
        node *temp=head;            // temp=1;

        head=p;             //  head=5
        p->next=temp;
       // cout<<p->val;             // 5->1->2
        return p;           //p
    }
    else
    {
        node * temp=head,*q;
        int c=1;
        while (c!=k-1)
        {
            temp=temp->next;
            c++;
        }

                                //    t  q
        q=temp->next;           // 1->2->3>4>NULL
        temp->next=p;           // adding link
        p->next=q;
        return head;
    }
}
int main()
{
    struct node *head=NULL;     // creating head

    for (int i=1;i<=10;i++)
        head=insertatlast(head,i);          // inserting one to 10;



    //print(head);
    //print_last_2(head);
    //find_x(head,3);
    head=insert_at_k(head,5,1);
    print(head);
}
