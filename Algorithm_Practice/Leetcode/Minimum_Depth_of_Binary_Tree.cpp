#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

 int depthRecursive(TreeNode * root){
    if(root->left == NULL && root->right == NULL)
        return 1;
    if(root->left == NULL)
        return depthRecursive(root->right) + 1;
    if(root->right == NULL)
        return depthRecursive(root->left) + 1;
    return min(depthRecursive(root->left) + 1,depthRecursive(root->right) + 1);
}

int minDepth(TreeNode* root) {
    int result = 0;
    if(root == NULL)
        return result;
    result = depthRecursive(root);
    return result;
}

int main(int argc, char const *argv[])
{
    minDepth(root);
    return 0;
}

/*

 */