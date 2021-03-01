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
bool equal_tree(node *r1, node *r2)
{
    if (r1==NULL||r2==NULL)
    {
        if (r1==r2)
            return true;
        else
            return false;
    }
    else
    {
        if (r1->data!=r2->data)
            return false;
        else
            return equal_tree(r1->left,r2->left)&&equal_tree(r1->right,r2->right);
    }
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
bool symmetric_tree(node *r1, node *r2)
{
    if (r1==NULL||r2==NULL)
    {
        if (r1==r2)
            return true;
        else
            return false;
    }
    else
    {
        if (r1->data!=r2->data)
            return false;
        else
            return symmetric_tree(r1->left, r2->right)&&symmetric_tree(r1->right, r2->left);
    }
}

bool check_mirror(node *root)
{
    if (root==NULL)
        return true;
    else
        return symmetric_tree(root->left, root->right);
}





int main()
{
    node *r1=NULL;
    node *r2=NULL;
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        r1=insert_in_bst(r1,x);
        //inorder(root);
        //cout<<endl;
    }
    /*cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        r2=insert_in_bst(r2,x);
        //inorder(root);
        //cout<<endl;
    }*/
    cout<<check_mirror(r1);
}
