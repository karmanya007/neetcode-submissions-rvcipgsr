class Solution {
public:
    bool isEqual(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2){
        for(char c = 'a'; c <= 'z'; c++){
            if(mp1[c] != mp2[c])
                return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        unordered_map<char, int> freqMap1, freqMap2;

        for(int i = 0; i < n; i++){
            freqMap1[s1[i]]++;
            freqMap2[s2[i]]++;
        }

        int i = 0;
        for(int j = n; j < m; j++){
            if(isEqual(freqMap1, freqMap2))
                return true;
            
            freqMap2[s2[j]]++;
            freqMap2[s2[i++]]--;
        }

        return isEqual(freqMap1, freqMap2);
    }
};
