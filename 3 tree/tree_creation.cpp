#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
};
node * create_node(int x)
{
    node * p=(node *) malloc(sizeof(node));
    p->data=x;
    p->right=NULL;
    p->left=NULL;
    return p;
}
node* insert_in_bst(node* root,int x)
{
    if (root==NULL)
    {
        node *p=create_node(x);
        root=p;
        return root;
    }
    else
    {
        if (root->data>x)       // x is smaller
            root->left=insert_in_bst(root->left,x);
        else
            root->right=insert_in_bst(root->right,x);
    }
    return root;
}
void inorder(node *root)
{
    if (root==NULL)
        return ;
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main()
{
    node *root=NULL;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        root=insert_in_bst(root,x);
        inorder(root);
        cout<<endl;
    }
}
