class Solution {
public:
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string &word){
        if(idx == word.length())
            return true;

        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] == '*' || board[i][j] != word[idx])
            return false;

        board[i][j] = '*';
        bool res = dfs(i + 1, j, idx + 1, board, word) ||
                    dfs(i - 1, j, idx + 1, board, word) || 
                    dfs(i, j + 1, idx + 1, board, word) ||
                    dfs(i, j - 1, idx + 1, board, word);
        board[i][j] = word[idx];

        return res;
    }       

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};
