/*
Given a string s, return the length of the longest substring that contains at
most two distinct characters.

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t size = s.length();
        if(size < 3) return size;

        int l = 0;
        int r = 0;
        int maxLength = 2;
        unordered_map<char, int> charIndexMap;
        while (r < size) {
            charIndexMap[s[r]] = r;
            ++r;

            if (charIndexMap.size() == 3) {
                int idx = INT_MAX;
                for (pair<char, int> entry : charIndexMap) {
                    idx = min(idx, entry.second);
                }
                charIndexMap.erase(s[idx]);
                l = idx + 1;
            }
            maxLength = max(maxLength, r - l);
        }
        return maxLength;
    }
};
