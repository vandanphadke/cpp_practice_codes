/*
Given an m x n gird of characters board and a string word, return true if word
exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where
adjacent cells are horizontally or vertically neighboring. The same letter cell
may not be used more than once.

Note: There will be some test cases with a board or a word larger than
constraints to test if your solution is using pruning.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCCED"
Output: true
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
word = "ABCB"
Output: false

*/

class Solution {
public:
      bool exist(vector<vector<char> > &board, string word) {
         m=board.size();
         n=board[0].size();
         for(int x=0;x<m;x++){
             for(int y=0;y<n;y++)
             {
                 if(isFound(board,word.c_str(),x,y))
                     return true;
             }
         }
         return false;
     }
private:
     int m;
     int n;

     bool isFound(vector<vector<char>> &board, const char* w, int x, int y)
     {
         if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
             return false;
         if(*(w+1)=='\0')
             return true;
         char t=board[x][y];
         board[x][y]='\0';
         if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
             return true;
         board[x][y]=t;
         return false;
     }
};
