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
    cout<<endl;
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

node * merge_list(node * p, node *q)
{
    node* head=NULL,*r;
    if (p==NULL)
        return q;
    else if (q==NULL)
        return p;
    else
    {
        // both are exist.
        if (p->val<q->val)
            head=p,p=p->next;
        else
            head=q,q=q->next;
        r=head;

        while (p!=NULL&&q!=NULL)
        {
            if (p->val<q->val)
                r->next=p, p=p->next;
            else
                r->next=q, q=q->next;
            r=r->next;
        }
        if (p==NULL)
            r->next=q;              // adding the left part of q
        else if (q==NULL)
            r->next=p;              //adding the left part of p
        return head;
    }
}
int main()
{
    //struct node *head=NULL;     // creating head

    //for (int i=1;i<=10;i++)
     //   head=insertatlast(head,i);          // inserting one to 10;

    //print(head);
    //print_last_2(head);
    //find_x(head,3);
   // head=insert_at_k(head,5,1);
    //print(head);



    node *p=NULL;
    for (int i=1;i<10;i++)
        p=insertatlast(p,i);
    print(p);
    node *q=NULL;
    for (int i=11;i<20;i++)
        q=insertatlast(q,i);
    print(q);

    node* head=merge_list(p,q);     // merging two link list
    print(head);

}
