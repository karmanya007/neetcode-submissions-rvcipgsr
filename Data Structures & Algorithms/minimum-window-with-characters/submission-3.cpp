class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) return "";
        
        unordered_map<char, int> countT, window;
        
        for(char &c : t) countT[c]++;
            
        int i = 0, maxLen = INT_MAX, have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};

        for(int j = 0; j < n; j++){
            char c = s[j];
            window[c]++;
            
            if(countT.count(c) && countT[c] == window[c]){
                have++;
            }
            
            while(i <= j && have == need){
                if(j - i + 1 < maxLen){
                    maxLen = j - i + 1;
                    res = {i, j};
                }
                
                window[s[i]]--;
                if(countT.count(s[i]) && window[s[i]] < countT[s[i]]){
                    have--;
                }
                
                i++;
            }
        }
        
        return maxLen == INT_MAX ? "" : s.substr(res.first, maxLen);
    }
};
