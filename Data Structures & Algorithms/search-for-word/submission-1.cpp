class Solution {
public:
    bool dfs(int r, int c, int idx, vector<vector<char>> &board, string &word){
        if(idx == word.length())
            return true;
        
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[idx] || board[r][c] == '#')
            return false;
        
        board[r][c] = '#';
        bool res = dfs(r + 1, c, idx + 1, board, word) ||
                   dfs(r, c + 1, idx + 1, board, word) ||
                   dfs(r - 1, c, idx + 1, board, word) ||
                   dfs(r, c - 1, idx + 1, board, word);
        board[r][c] = word[idx];
        
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; ++j){
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }
        
        return false;
    }
};
