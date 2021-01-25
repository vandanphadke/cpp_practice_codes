/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

0 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0) return "";
      if (strs.size() == 1) return strs[0];
      string res = lcp(strs[0], strs[1]);
      for (int i = 2; i < strs.size(); i++) {
        res = lcp(res, strs[i]);
      }
      return res;
    }

    string lcp(string X, string Y) {
      int i = 0, j = 0;
      while (i < X.length() && j < Y.length()) {
        if (X[i] != Y[j])
          break;
        i++, j++;
      }
      return X.substr(0, i);
    }
};
