class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        
        vector<int> freq(26, 0);

        auto maxFreq = [&]() -> int {
            int maxF = 0;
            for(int i = 0; i < 26; i++){
                maxF = max(maxF, freq[i]);
            }
            
            return maxF;
        };
        
        int i = 0, maxLen = 1;
        
        for(int j = 0; j < n; j++){
            freq[s[j] - 'A']++;
            
            while(i < j && (j - i + 1 - maxFreq() > k)){
                freq[s[i++] - 'A']--;
            }
            
            maxLen = max(maxLen, j - i + 1);
        }
        
        return maxLen;
    }
};
