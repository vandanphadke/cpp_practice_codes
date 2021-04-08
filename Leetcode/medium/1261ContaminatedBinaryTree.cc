/*
Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

You need to first recover the binary tree and then implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
bool find(int target) Return if the target value exists in the recovered binary tree.
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
class FindElements {
public:
    FindElements(TreeNode* root) {
        root_ = root;
        if(!root_) return;
        root_->val = 0;
        recover(root_);
    }

    void recover(TreeNode* node) {
        if(!node) return;

        if(node->left) node->left->val = (node->val * 2) + 1;
        if(node->right) node->right->val = (node->val * 2) + 2;
        recover(node->left);
        recover(node->right);
    }

    bool find(int target) {
        int temp = target;
        vector<int> ancestry;
        ancestry.push_back(target);
        while(target > 0) {
            target = (target - 1) / 2;
            ancestry.push_back(target);
        }
        return find(root_, temp, ancestry);
    }

    private:
    TreeNode* root_;

    bool find(TreeNode* node, int target, vector<int> ancestry) {
        for(int i = ancestry.size() - 1; i >= 1; --i){
            if(!node) return false;
            if(node->val != ancestry[i]) return false;
            if(node->left && node->left->val == ancestry[i-1]){
                node = node->left;
            } else if(node->right && node->right->val == ancestry[i-1]) {
                node = node->right;
            } else {
                return false;
            }
        }
        if(node && node->val == target) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
