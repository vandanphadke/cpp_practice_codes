/*
On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions
of the Black Queens, and a pair of coordinates king that represent the position
of the White King, return the coordinates of all the queens (in any order)
that can attack the King.

Example 1:

Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:
The queen at [0,1] can attack the king cause they're in the same row.
The queen at [1,0] can attack the king cause they're in the same column.
The queen at [3,3] can attack the king cause they're in the same diagnal.
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1].
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0].
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.
*/

struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const
    {
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1 ^ h2;
    }
};

const int xPos[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int yPos[] = {0, 1, 1, 1, 0, -1, -1, -1};

class Solution {
private:
    bool isValid(int x, int y) {
        return (x >= 0) && (y >=0) && (x < 8) && (y < 8);
    }

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<pair<int, int>, pair_hash> queensSet;
        vector<vector<int>> result;
        for (size_t i = 0; i < queens.size(); i++) {
            queensSet.emplace(make_pair(queens[i][0], queens[i][1]));
        }

        for (size_t i = 0; i < 8; i++) {
            int currentX = king[0];
            int currentY = king[01];
            while (isValid(currentX, currentY)) {
                if (queensSet.find(make_pair(currentX, currentY)) == queensSet.end()) {
                    // Queen not found
                    currentX = currentX + xPos[i];
                    currentY = currentY + yPos[i];
                } else {
                    vector<int> temp;
                    temp.push_back(currentX);
                    temp.push_back(currentY);
                    result.push_back(temp);
                    break;
                }
            }
        }
        return result;
    }
};
