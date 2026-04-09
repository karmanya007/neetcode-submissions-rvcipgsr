class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
    
public:
    TrieNode() : endOfWord(false) {}
    
    void insert(string word) {
        TrieNode *cur = this;
        
        for(char &w : word){
            if(!(cur->children.count(w)))
                cur->children[w] = new TrieNode();
            cur = cur->children[w];
        }
        
        cur->endOfWord = true;
    }
};

class Solution {
public:
    void dfs(int r, int c, TrieNode *node, string word, vector<vector<char>> &board, unordered_set<string> &res){
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#'
            || !node->children.count(board[r][c]))
            return;
        
        node = node->children[board[r][c]];
        word += board[r][c];
        if(node->endOfWord)
            res.insert(word);
        
        char temp = board[r][c];
        board[r][c] = '#';
        
        dfs(r + 1, c, node, word, board, res);
        dfs(r - 1, c, node, word, board, res);
        dfs(r, c + 1, node, word, board, res);
        dfs(r, c - 1, node, word, board, res);
        
        board[r][c] = temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        
        TrieNode *trie = new TrieNode;
        for(string &w : words)
            trie->insert(w);
        
        unordered_set<string> res;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, trie, "", board, res);
            }
        }
        
        return vector<string>(res.begin(), res.end());
    }
};
