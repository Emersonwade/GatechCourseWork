#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 */

/**
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
    bool areSymmetricTrees(TreeNode* left, TreeNode* right){
        if( (left == NULL && right != NULL) || (left != NULL && right == NULL) )
            return false;
        if(left == NULL && right == NULL)
            return true;
        
        if(left->val != right->val)
            return false;
        else {
            return areSymmetricTrees(left->left, right->right) &&
            areSymmetricTrees(left->right, right->left);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return areSymmetricTrees(root->left, root->right);
    }
};

int main(int argc, char const *argv[])
{
    
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    return 0;
}

/*
使用递归解决树是否symmetric，通过判断子树，子树的左子树右子树。另外需要注意判断递归的边界条件。
 */

