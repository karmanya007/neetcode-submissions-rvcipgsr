class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int i = 0, maxLength = 0;
        unordered_map<char, int> mp;
        
        for(int j = 0; j < n; j++){
            mp[s[j]]++;
            
            while(i < j && mp.size() < (j - i + 1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            
            maxLength = max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
};
