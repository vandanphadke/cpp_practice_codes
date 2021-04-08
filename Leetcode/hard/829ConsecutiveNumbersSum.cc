/*
Given a positive integer N, how many ways can we write it as a sum of
consecutive positive integers?

Example 1:

Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3
Example 2:

Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
*/

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int rangeX = sqrt(2*N);
        int result = 1;
        for (int x = 2; x <= rangeX; x++) {
            int temp = (2*N - x*(x - 1));
            if ((temp > 0) && (temp % (2*x)) == 0) {
                cout << x << endl;
                ++result;
            }
        }
        return result;
    }
};
