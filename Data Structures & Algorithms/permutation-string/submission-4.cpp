class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        
        vector<int> freqMap1(26, 0), freqMap2(26, 0);

        for(int i = 0; i < n; i++){
            freqMap1[s1[i] - 'a']++;
            freqMap2[s2[i] - 'a']++;
        }

        int i = 0;
        for(int j = n; j < m; j++){
            if(freqMap1 == freqMap2)
                return true;
            
            freqMap2[s2[j] - 'a']++;
            freqMap2[s2[i++] - 'a']--;
        }

        return freqMap1 == freqMap2;
    }
};
