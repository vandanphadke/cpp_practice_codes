/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find
minimum cost to reach the top of the floor, and you can either start from the step
with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int temp1 = 0, temp2 = 0, N = cost.size();
        for (int i = N-1; i >= 0; --i) {
            int temp = cost[i] + min(temp1, temp2);
            temp2 = temp1;
            temp1 = temp;
        }
        return min(temp1, temp2);
    }
};
