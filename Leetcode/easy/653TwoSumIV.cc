/*
Given the root of a Binary Search Tree and a target number k, return true
if there exist two elements in the BST such that their sum is equal to the
given target.
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

    bool findTarget(TreeNode* root, int k) {
        inorder_traversal(root);
        int l = 0, r = inorderList.size() - 1;
        while (l < r) {
            int current = inorderList[l] + inorderList[r];
            if (current == k) {
                return true;
            } else if (current < k) {
                ++l;
            } else {
                --r;
            }
        }
        return false;
    }

private:
    vector<int> inorderList;

    void inorder_traversal(TreeNode* node){
        if (!node) return;
        inorder_traversal(node->left);
        inorderList.push_back(node->val);
        inorder_traversal(node->right);
    }
};
