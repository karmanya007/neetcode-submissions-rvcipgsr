class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        unordered_map<char, int> freqMap;
        int i = 0, maxLength = 0;

        for(int j = 0; j < n; j++){
            freqMap[s[j]]++;

            while(i < j && freqMap.size() < j - i + 1){
                freqMap[s[i]]--;
                if(freqMap[s[i]] == 0) freqMap.erase(s[i]);
                i++;
            }

            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};
