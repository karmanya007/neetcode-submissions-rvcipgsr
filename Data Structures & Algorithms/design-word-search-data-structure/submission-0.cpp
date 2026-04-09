struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class WordDictionary {
private:
    TrieNode *root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *cur = root;
        
        for(char &w : word){
            if(!(cur->children.count(w)))
                cur->children[w] = new TrieNode();
            cur = cur->children[w];
        }
        
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(0, root, word);
    }
    
private:
    bool dfs(int idx, TrieNode *root, string &word){
        TrieNode *cur = root;
        
        for(int i = idx; i < word.size(); i++){
            char c = word[i];
            
            if(c == '.'){
                for(auto &[ch, child] : cur->children){
                    if(!child) continue;
                    if(dfs(i + 1, child, word)) return true;
                }
                return false;
            }
            else {
                if(!cur->children.count(c))
                    return false;
                cur = cur->children[c];
            }
        }
        
        return cur->endOfWord;
    }
};