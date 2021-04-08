/*
Given an array nums with n objects colored red, white, or blue, sort them in-place
so that objects of the same color are adjacent, with the colors in the order red,
white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white,
and blue, respectively.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, current = 0;
        while (current <= j) {
            if (nums[current] == 0) {
                swap(nums, i, current);
                ++i;
                ++current;
            } else if (nums[current] == 2) {
                swap(nums, j, current);
                --j;
            } else {
                ++current;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
