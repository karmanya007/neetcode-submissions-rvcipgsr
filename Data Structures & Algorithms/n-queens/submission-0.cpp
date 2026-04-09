class Solution {
public:
    bool check(int row, int col, vector<string> &board){
        for(int r = 0; r < board.size(); r++){
            if(board[r][col] == 'Q') // If there is already a queen in the same column
                return false;

            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == 'Q' && abs(r - row) == abs(c - col)) // If there is already a queen in the same diagonal
                    return false;
            }
        }

        return true;
    }

    void backtrack(int row, int n, vector<string> &board, vector<vector<string>> &res){
        // Base case
        if(row == n)
            res.push_back(board);

        // Possible moves to place the queen in a column for a given row
        for(int col = 0; col < n; col++){
            // Check if can place the queen in the (row, col)
            if(check(row, col, board)){
                board[row][col] = 'Q';

                backtrack(row + 1, n, board, res);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board, res);

        return res;
    }
};
