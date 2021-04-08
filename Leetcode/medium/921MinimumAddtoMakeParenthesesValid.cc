/*
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example 1:

Input: "())"
Output: 1
Example 2:

Input: "((("
Output: 3
Example 3:

Input: "()"
Output: 0
Example 4:

Input: "()))(("
Output: 4
*/

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> paranStack;
        int extra = 0;
        for (size_t i = 0; i < S.length(); i++) {
            if (S[i] == '(') {
                paranStack.push(S[i]);
            } else {
                if (paranStack.empty()) {
                    ++extra;
                } else {
                    paranStack.pop();
                }
            }
        }
        extra += paranStack.size();
        return extra;
    }
};
