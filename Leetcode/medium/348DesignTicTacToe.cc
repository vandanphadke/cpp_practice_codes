/*
Assume the following rules are for the tic-tac-toe game on an n x n board between two players:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves are allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Implement the TicTacToe class:

TicTacToe(int n) Initializes the object the size of the board n.
int move(int row, int col, int player) Indicates that player with id player
plays at the cell (row, col) of the board. The move is guaranteed to be a valid move.
Follow up:
Could you do better than O(n2) per move() operation?

Example 1:

Input
["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
[[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
Output
[null, 0, 0, 0, 0, 0, 0, 1]

Explanation
TicTacToe ticTacToe = new TicTacToe(3);
Assume that player 1 is "X" and player 2 is "O" in the board.
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
*/

class TicTacToe {
private:
    vector<vector<int>> board;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        for (size_t i = 0; i < n; i++) {
            vector<int> temp;
            for (size_t j = 0; j < n; j++) {
                temp.push_back(-1);
            }
            board.push_back(temp);
        }
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        // Check row if wins
        bool loses = false;
        for (size_t i = 0; i < size; i++) {
            if (board[row][i] != player) {
                loses = true;
                break;
            }
        }
        if (!loses) {
            return player;
        }

        // Check column if wins
        loses = false;
        for (size_t i = 0; i < size; i++) {
            if (board[i][col] != player) {
                loses = true;
                break;
            }
        }
        if (!loses) {
            return player;
        }

        int i = 0, j = 0;
        loses = false;
        while(i < size && j < size) {
            if (board[i][j] != player) {
                loses = true;
                break;
            }
            ++i;++j;
        }
        if (!loses) {
            return player;
        }

        i = 0, j = size-1;
        loses = false;
        while(i < size && j >= 0) {
            if (board[i][j] != player) {
                loses = true;
                break;
            }
            ++i;--j;
        }
        if (!loses) {
            return player;
        }

        return 0;
    }
};
