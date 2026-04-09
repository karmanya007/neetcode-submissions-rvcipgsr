struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class PrefixTree {
private:
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        
        for(char &w : word){
            if(!(cur->children.count(w)))
                cur->children[w] = new TrieNode();
            cur = cur->children[w];
        }
        
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        
        for(char &w : word){
            if(!(cur->children.count(w)))
                return false;
            cur = cur->children[w];
        }
        
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        
        for(char &p : prefix){
            if(!(cur->children.count(p)))
                return false;
            cur = cur->children[p];
        }
        
        return true;
    }
};