#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*next;       // self referncial struture
};
// struct node is a user datatype
// int is inbuild datatype
// fucntion to create node
node *create_node(int x)      // x is data
{
    node *p=(node *)malloc(sizeof (node));      // malloc is return void type *
    p->data=x;
    p->next=NULL;
    return p;
}
int find_max(node *head)
{
    int mx=-1;
    while (head!=NULL)
    {
        if (head->data>mx)
            mx=head->data;
        head=head->next;
    }
    return mx;
}
// insert element at first place in linked list
node* insert_at_first(node *head,int x)
{
    node *temp=head;
    node *p=create_node(x);
    head=p;
    p->next=temp;
    return head;
}
void printLL(node *head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
// inseration  at the last
node* insert_last(node *head, int x)
{
    node *p=create_node(x);
    if (head==NULL)     // no element in the linked list
        return p;
    else
    {
        node *q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
        return head;
    }
}
int find_middle(node *head)
{
    if (head==NULL)
        return -1;
    else if (head->next==NULL)
        return head->data;
    else
    {
        node *p=head;
        node *q=head;
        while (q!=NULL)
        {
            q=q->next;
            if (q==NULL)
                break;
            q=q->next;
             if (q==NULL)
                break;
            p=p->next;
        }
        return p->data;
    }
}
int main()
{
    node *head=NULL;
    head=create_node(5);
    head->next=create_node(10);
    head->next->next=create_node(15);
    head->next->next->next=create_node(20);

    /*while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }*/
    head=insert_at_first(head,0);
    head=insert_last(head,25);
    printLL(head);
    cout<<find_middle(head);
    //cout<<find_max(head);
}
