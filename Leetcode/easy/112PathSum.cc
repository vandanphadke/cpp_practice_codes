/*
Given the root of a binary tree and an integer targetSum, return true
if the tree has a root-to-leaf path such that adding up all the values along
the path equals targetSum.

A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:

Input: root = [1,2], targetSum = 0
Output: false
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
   bool hasPathSum(TreeNode* root, int targetSum) {
       if(root == NULL) return 0;
       return currentTotal(root, targetSum, 0);
   }

   bool currentTotal(TreeNode* root, int targetSum, int currentSum) {
       if (root -> left == NULL && root -> right == NULL) {
         if ((currentSum + root -> val) == targetSum) {
           return true;
         }
         else {
           return false;
         }
       }
       bool leftRecurse = false;
       if (root -> left != NULL) {
         leftRecurse = currentTotal(root -> left, targetSum,
           currentSum + root -> val);
       }
       bool rightRecurse = false;
       if (root -> right != NULL) {
         rightRecurse = currentTotal(root -> right, targetSum,
           currentSum + root -> val);
       }
       return (leftRecurse || rightRecurse);
   }
};
