/*
Given a non-empty string s and a dictionary wordDict containing a list
of non-empty words, determine if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.

Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set <string> dictionary;
    for (string word : wordDict) {
      dictionary.insert(word);
    }
    int n = s.length();
    bool dp[n];
    memset(dp, false, n);
    for (int i = 0; i < n; i++) {
      if(dictionary.find(s.substr(0, i+1)) != dictionary.end()) {
          dp[i] = true;
          continue;
      }

      for (int j = 0; j < i; j++) {
        if (dp[j] && (dictionary.find(s.substr(j+1, (i-j))) != dictionary.end())) {
          cout << j << i << endl;
          cout << s.substr(j+1, (i-j)) << endl;
          dp[i] = true;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i)
      cout << dp[i];
    return dp[n-1];
  }
};
