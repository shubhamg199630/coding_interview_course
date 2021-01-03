//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//Example :
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//The above binary tree is symmetric.
//But the following is not:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Return 0 / 1 ( 0 for false, 1 for true ) for this problem



// Logic is same as that of identical tree but here we need a root of same tree in a new function.






int isSymhelper(TreeNode *A, TreeNode *B)
{
   if (A==NULL&&B!=NULL||B==NULL&&A!=NULL)     // any one of them is NULL return 0
        return 0;
    else if (A==NULL&&B==NULL)          // both null of same true
        return 1;
    else 
    {
        if (A->val!=B->val)
            return 0;
        else 
            return isSymhelper(A->left,B->right)&&isSymhelper(A->right,B->left);
            // left of A with right of B and same way 
            // right of B with left of A
            
    }
}
int Solution::isSymmetric(TreeNode* A) {
    if (A==NULL)
        return 1;
    return (isSymhelper(A->left,A->right));
}
