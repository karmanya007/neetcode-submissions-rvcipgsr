class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                int n = s.length();
        
        int i = 0, maxLength = 0;
        unordered_map<char, int> mp;
            
        for(int j = 0; j < n; j++){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            
            maxLength = max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
};
