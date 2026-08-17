class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.length();
        int i = 0, maxFreq = 0, maxLen = 1;
        vector<int> freq(26, 0);

        for(int j = 0; j < len; j++){
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            while(i < j && (j - i + 1) - maxFreq > k){
                freq[s[i++] - 'A']--;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
