/*
Given an array nums and two types of queries where you should update the value
of an index in the array, and retrieve the sum of a range in the array.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the subarray
nums[left, right] (i.e., nums[left] + nums[left + 1], ..., nums[right]).

Example 1:

Input
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
Output
[null, 9, null, 8]

Explanation
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // return 9 = sum([1,3,5])
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // return 8 = sum([1,2,5])
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n != 0) {
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    void update(int index, int val) {
        int treeIndex = index + n;
        tree[treeIndex] = val;
        while (treeIndex > 0) {
            int left = treeIndex;
            int right = treeIndex;
            if (treeIndex % 2 == 0) {
                right = treeIndex + 1;
            } else {
                left = treeIndex - 1;
            }
            tree[treeIndex / 2] = tree[left] + tree[right];
            treeIndex /= 2;
        }
    }

    int sumRange(int left, int right) {

    }

private:
    int *tree;
    int n;

    void buildTree(vector<int>& nums) {
        for (int i = n, j = 0;  i < 2 * n; i++, j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    int sumRangeRecurse(int left, int right, int limitLeft,
        int limitRight, int index) {
        if (left >= limitLeft && right <= limitRight) {
            return tree[index];
        }

        if (right < leftLimit || left > rightLimit) {
            return 0;
        }

        int mid = limitLeft + (limitRight - limitLeft)/2;
        return sumRangeRecurse(left, mid, limitLeft, limitRight, (2*index + 1)) +
            sumRangeRecurse(mid+1, right, limitLeft, limitRight, (2*index + 2));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
