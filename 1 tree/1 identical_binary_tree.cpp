//https://www.interviewbit.com/courses/programming/topics/tree-data-structure/


//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
//
//Return 0 / 1 ( 0 for false, 1 for true ) for this problem
//
//Example :
//
//Input : 
//
//   1       1
//  / \     / \
// 2   3   2   3
//
//Output : 
//  1 or True
  



// We need root of both the tree as without them we cannot check
// see comment very easy program 




int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if (A==NULL&&B!=NULL||B==NULL&&A!=NULL)     // any one of them is NULL return 0
        return 0;
    else if (A==NULL&&B==NULL)          // both null of same true
        return 1;
    else
    {
        if (A->val!=B->val)             // value not matching so 0
            return 0;
        else                            // check left and right tree
            return isSameTree(A->left, B->left)&&isSameTree(A->right,B->right);
    }
}