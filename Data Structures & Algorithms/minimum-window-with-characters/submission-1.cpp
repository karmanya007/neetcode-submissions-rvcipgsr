class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if(m > n) return "";
        
        unordered_map<char, int> mp1, mp2;
        
        for(char &c : t) mp1[c]++;

        auto contain = [&]() -> bool {
            for(auto &x : mp1){
                if(mp2[x.first] < x.second)
                    return false;
            }
            
            return true;
        };
            
        int i = 0;
        string res = "";
        bool found = false;

        for(int j = 0; j < n; j++){
            mp2[s[j]]++;
            
            while(i <= j && contain()){
                string tempStr = s.substr(i, j - i + 1);
                if(!found || res.length() > tempStr.length()){
                    res = tempStr;
                    found = true;
                }
                
                mp2[s[i]]--;
                if(mp2[s[i]] == 0) mp2.erase(s[i]);
                
                i++;
            }
        }
        
        return res;
    }
};
