/*
In an alien language, surprisingly they also use english lowercase letters,
but possibly in a different order. The order of the alphabet is some permutation
of lowercase letters.

Given a sequence of words written in the alien language, and the order of
the alphabet, return true if and only if the given words are sorted
lexicographicaly in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1],
hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is
shorter (in size.) According to lexicographical rules "apple" > "app",
because 'l' > '∅', where '∅' is defined as the blank character which is less
than any other character (More info).
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charIndexMap;
        for (size_t i = 0; i < order.length(); i++) {
            charIndexMap[order[i]] = i;
        }
        for (size_t i = 0; i < words.size() - 1; i++) {
            if (!checkWordsLexicography(words[i], words[i+1],charIndexMap)) {
                return false;
            }
        }
        return true;
    }

    bool checkWordsLexicography(string word1, string word2,
        unordered_map<char, int>& charIndexMap) {
        int i = 0, j = 0;
        while (i < word1.length() && j < word2.size()) {
            if (charIndexMap[word1[i]] > charIndexMap[word2[i]]) {
                return false;
            }
            if (charIndexMap[word1[i]] < charIndexMap[word2[i]]) {
                return true;
            }
            ++i;
            ++j;
        }
        if (word1.length() > word2.length()) {
            return false;
        }
        return true;
    }
};
