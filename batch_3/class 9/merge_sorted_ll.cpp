#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node * next;
};
node * create_node(int x)
{
    node *p=(node*)malloc(sizeof (node));
    p->val=x;
    p->next=NULL;
    return p;
}
node* insert_at_first( node * head,int x)
{
    node *p= create_node(x);
    node *temp=head;
    head=p;
    head->next=temp;
    return head;
}
node * merge_two_sorted_ll(node *head1, node*head2)
{
    node *head=NULL,*q=NULL,*temp=NULL;
    node *i=head1,*j=head2;
    while (i!=NULL&&j!=NULL)
    {
        if (i->val>j->val)          // pick j element
        {
            temp=j;
            j=j->next;
        }
        else                    // pick i element
        {
            temp=i;
            i=i->next;

        }
        if (head==NULL)
        {
            head=temp;
            q=head;
        }
        else
        {
            q->next=temp;
            q=q->next;
        }
    }
    if (i==NULL)
    {
        if (head==NULL)
            return j;
        else
            q->next=j;
    }
    else if (j==NULL)
    {
        if (head==NULL)
            return i;
        else
            q->next=i;
    }
    return head;
}
node * find_middle_LL( node *head)
{
    node *p=head, *q=head;
    while (q!=NULL)
    {
        q=q->next;
        if (q==NULL)
            return p;
        q=q->next;
        if (q==NULL)
            return p;
        p=p->next;
    }
}
void printll(node *head)
{
    while (head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}
node * merge_sort(node *head)
{
    node *mid=find_middle_LL(head);
    //cout<<mid->val<<"A ";
    if (head!=NULL&&head ==mid&&mid->next==NULL)
        return head;
    else
    {
        node *head2=mid->next;
        mid->next=NULL;
        merge_sort(head);       // left part;
        merge_sort(head2);      // right part;
        //printll(head);
        //printll(head2);
        return merge_two_sorted_ll(head, head2);
    }
}

int main()
{
    node *head1=NULL, *head2=NULL;
    int x;
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>x;
        head1=insert_at_first(head1,x);
        //insert_at_last(head1, x);
    }
    printll(head1);
    /*for (int i=0; i<4; i++)
    {
        cin>>x;
        head2=insert_at_first(head2,x);
    }
    node *head=merge_two_sorted_ll(head1,head2);*/
    node *head=merge_sort(head1);
    printll(head);
}
