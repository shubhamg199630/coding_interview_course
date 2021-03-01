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
node *create_tree(node *root)
{
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        cin>>x;
        root=insert_in_bst(root,x);
        //cout<<root<<" ";
        inorder(root);
        cout<<endl;
    }
    return root;
}
int count_leaf_node(node *root)
{
    if (root==NULL)
        return 0;
    else if (root->left==NULL&&root->right==NULL)
        return 1;
    else
        return count_leaf_node(root->left)+count_leaf_node(root->right);
}
int sum_leaf_node(node *root)
{
    if (root==NULL)
        return 0;
    else if (root->left==NULL&&root->right==NULL)
        return root->data;
    else
        return sum_leaf_node(root->left)+sum_leaf_node(root->right);
}
int height_tree(node *root)
{
    if (root==NULL)
        return 0;
    else if (root->left==NULL&&root->right==NULL)
        return 0;
    else
        return max(height_tree(root->left),height_tree(root->right))+1;
}
int main()
{
    node *root=NULL;
    root=create_tree(root);
    cout<<height_tree(root);
}
