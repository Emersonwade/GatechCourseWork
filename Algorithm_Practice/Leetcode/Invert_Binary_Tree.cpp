#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void invertNode(TreeNode* treeNode){
        if(treeNode->left != NULL){
            invertNode(treeNode->left);
        }
        
        if(treeNode->right != NULL){
            invertNode(treeNode->right);
        }
        
        TreeNode * temp = treeNode->left;
        treeNode->left = treeNode->right;
        treeNode->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL)
            invertNode(root);
        return root;
    }
};

