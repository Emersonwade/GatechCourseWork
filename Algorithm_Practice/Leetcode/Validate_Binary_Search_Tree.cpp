#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

bool validBST(TreeNode* root, long min, long max){
    if(root == NULL)
        return true;
    if(root->val <= min || root->val >= max)
        return false;
    
    return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return validBST(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
对一个二叉搜索树来说，每个节点将会有一个最小值或者最大值，也有可能都有。对于左子树来说，将会有一个最大值的限制，而对于右子树
则会有最小值的限制。
 */

