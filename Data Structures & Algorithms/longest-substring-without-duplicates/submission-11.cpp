class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0, maxLen = 0;
        unordered_map<char, int> freqMap;

        for(int j = 0; j < n; j++){
            freqMap[s[j]]++;

            while(i < j && freqMap[s[j]] > 1){
                freqMap[s[i]]--;
                if(freqMap[s[i] == 0])
                    freqMap.erase(s[i]);

                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
