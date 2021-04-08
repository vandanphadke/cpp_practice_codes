/*
Given two strings S and T, return if they are equal when both are typed into empty
text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length(), j = T.length();
        int skipI = 0, skipJ = 0;
        while ((i >= 0) || (j >= 0)) {
            while ((i >= 0) && (S[i] == '#')) {
                --i;
                ++skipI;
            }
            while ((j >= 0) && (S[j] == '#')) {
                --j;
                ++skipJ;
            }

            while ((skipI != 0) && (i >= 0)) {
                --i;
                --skipI;
            }

            while ((skipJ != 0) && (j >= 0)) {
                --j;
                --skipJ;
            }

            if ((i >= 0) && (j >= 0) && (S[i] != T[j])) {
                return false;
            }

            if ((i >= 0) || (j >= 0)) {
                return false;
            }
            --i;
            --j;
        }

        return true;
    }
};
