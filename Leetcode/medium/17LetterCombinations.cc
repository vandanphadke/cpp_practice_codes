/*
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:

  unordered_map<char, string> keypadMap = {
      {'2', "abc"},
      {'3', "def"},
      {'4', "ghi"},
      {'5', "jkl"},
      {'6', "mno"},
      {'7', "rspq"},
      {'8', "tuv"},
      {'9', "wxyz"}
  };


    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits == "") return result;
        string currentStr = "";
        generateLetterCombinations(digits, 0, currentStr, result);
        return result;
    }



    void generateLetterCombinations(string digits, int index,
      string currentStr, vector<string> &result) {
        if (index == digits.size()) {
          result.push_back(currentStr);
          return;
        }

        string possibleChars = keypadMap[digits[index]];
        for (int i = 0; i < possibleChars.size(); i++) {
          generateLetterCombinations(digits, index + 1, currentStr + possibleChars[i], result);
        }
    }
};
