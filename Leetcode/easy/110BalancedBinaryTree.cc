/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool isBalanced(TreeNode* root) {
     if (root == NULL) {
       return true;
     }
     return (height(root) != -1);
   }

   int height(TreeNode* root) {
     if (root == NULL) {
       return 0;
     }
     int l = (root -> left == NULL) ? 0 : height(root -> left);
     int r = (root -> right == NULL) ? 0 : height(root -> right);
     if (l == -1 || r == -1) {
       return -1;
     }
     else if (abs(l - r) > 1) {
       return -1;
     }
     else
       return max(l, r) + 1;
   }
};
