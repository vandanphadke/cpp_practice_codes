/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]]
*/

class Solution {
private:
    unordered_set<char> possibleChars;

    pair<int, int> findFirstUnfilled(vector<vector<char>>& board) {
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        possibleChars.emplace('1');possibleChars.emplace('2');possibleChars.emplace('3');
        possibleChars.emplace('4');possibleChars.emplace('5');possibleChars.emplace('6');
        possibleChars.emplace('7');possibleChars.emplace('8');possibleChars.emplace('9');

        fillSudokuRecurse(board);

    }

    boolean fillSudokuRecurse(vector<vector<char>>& board) {
        pair<int, int> unfilled = findFirstUnfilled(board);
        if (unfilled.first == -1) {
            return true;
        }
        // Find first unfilled cell
        int i = unfilled.first;
        int j = unfilled.second;

        // Find possibilities for (i, j)
        unordered_set<char> temp = possibleChars;
        // Remove column elements
        for (size_t newi = 0; newi < 9; newi++) {
            if (board[newi][j] != '.') {
                temp.erase(board[newi][j]);
            }
        }
        // Remove row elements
        for (size_t newj = 0; newj < 9; newj++) {
            if (board[i][newjj] != '.') {
                temp.erase(board[newi][j]);
            }
        }
        // TODO: Remove 3*3 matrix elements

        for (auto& it : possibleChars) {
            board[i][j] = (char) it;
            if (fillSudokuRecurse(board)) {
                return true;
            }
        }
        return false;
    }

};
