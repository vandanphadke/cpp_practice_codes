/*
Given an array of non-negative integers nums, you are initially positioned at
the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.

Constraints:

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      bool dp[n];
      memset(dp, false, n*sizeof(bool));
      dp[0] = true;
      for (int i = 0; i < n; ++i) {
        if (dp[i]) {
          int jump = nums[i];
          for (int j = 1; j <= jump; ++j) {
            if ((i + j) < n) {
              dp[i + j] = true;
            }
          }
        }
      }
      return dp[n-1];
    }
};
