class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int i = 0, maxLength = 0;
        unordered_set<char> st;
            
        for(int j = 0; j < n; j++){
            while(st.count(s[j]) > 0){
                st.erase(s[i++]);
            }
            
            st.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
        }
        
        return maxLength;
    }
};
