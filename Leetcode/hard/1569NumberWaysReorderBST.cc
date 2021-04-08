#define MOD 1000000007

int mypow(long x) {
    int n = 1e9 + 5, mod = 1e9 + 7;
    long res = 1;
    while(n) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

long comb(int m, int n) {
    int mod = 1e9 + 7;
    long num = 1, dem = 1;
    for (int i=m; i>= m - n + 1; --i)
        num = (num * i) % mod;
    for (int i=1; i<=n; ++i)
        dem = (dem * mypow(i)) % mod;

    return (num * dem) % mod;
}

struct TreeNode1 {
    TreeNode1* left;
    TreeNode1* right;
    int val;

    TreeNode1(int _val) {
        val = _val;
        left = right = nullptr;
    }
};

class BST {
public:
    TreeNode1* root;

    BST() {
        root = nullptr;
    }

    void insert(int val){
        root = insert(root, val);
    }

    void inorderTraversal(){
        inorderTraversal(root);
    }

private:

    TreeNode1* insert(TreeNode1* current, int val) {
        if (!current) {
            return new TreeNode1(val);
        }

        if (val < current->val) {
            current->left = insert(current->left, val);
        } else {
            current->right = insert(current->right,val);
        }
        return current;
    }

    void inorderTraversal(TreeNode1* current) {
        if (current->left) {
            inorderTraversal(current->left);
        }
        if (current->right) {
            inorderTraversal(current->right);
        }
    }
};


class Solution {
public:
    int numOfWays(vector<int>& nums) {
        BST bst;
        for (size_t i = 0; i < nums.size(); i++) {
            bst.insert(nums[i]);
        }
        //bst.inorderTraversal();
        pair<int, int> ans = findNumberOfWaysRecurse(bst.root);
        return (int)((ans.first - 1) % MOD);
    }

    pair<long, long> findNumberOfWaysRecurse(TreeNode1* root) {
        cout << root -> val << endl;
        if(!root->left && !root->right) return make_pair(1, 1);
        long leftWays = 1, rightWays = 1, numLeft = 0, numRight = 0;
        if(root->left) {
           pair<long, long> leftAns = findNumberOfWaysRecurse(root->left);
           leftWays = leftAns.first;
            numLeft = leftAns.second;
        }
        if(root->right) {
            pair<long, long> rightAns = findNumberOfWaysRecurse(root->right);
            rightWays = rightAns.first;
            numRight = rightAns.second;
        }

        cout << "L" << leftWays << "  " << numLeft << endl;
        cout << "R" << rightWays << "  " << numRight << endl;

        long totalNodes = numLeft + numRight + 1;
        if(!root->left) {
            return make_pair(rightWays % MOD, totalNodes % MOD) ;
        } else if(!root->right) {
            return make_pair(leftWays % MOD , totalNodes % MOD);
        } else {
            long long temp1 = ((leftWays % MOD) * (rightWays % MOD)) % MOD;
            long long temp2 = (temp1 * (comb(totalNodes - 1, numRight) % MOD)) % MOD;
            int totalWays = (int) temp2;

            cout << "Ans  " << totalWays << endl;
            return make_pair(totalWays, totalNodes);
        }
    }


};
