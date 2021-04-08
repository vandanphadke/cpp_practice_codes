/*
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum and
return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [0]
Output: 0
Example 4:

Input: nums = [-1]
Output: -1
Example 5:

Input: nums = [-100000]
Output: -100000


Constraints:

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105


Follow up: If you have figured out the O(n) solution,
try coding another solution using the divide and conquer
approach, which is more subtle.
*/

#include<iostream>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int total_max = nums[0];
      int current_max = nums[0];

      for (int i = 0; i < nums.size(); ++i) {
        current_max = max(current_max + nums[i], nums[i]);
        total_max = max(current_max, total_max);
      }

      return total_max;
    }
};
