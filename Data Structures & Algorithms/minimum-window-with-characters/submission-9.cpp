class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();

        unordered_map<char, int> freqMap1, freqMap2;

        for(char &c : t)
            freqMap2[c]++;

        auto isValid = [&]() -> bool {
            for(auto &x : freqMap2){
                if(freqMap1[x.first] < x.second)
                    return false;
            }
            
            return true;
        };

        pair<int, int> res = {-1, -1};
        int i = 0;

        for(int j = 0; j < n; j++){
            freqMap1[s[j]]++;

            while(i <= j && isValid()){
                if(res.first == -1 || res.second - res.first + 1 > j - i + 1)
                    res = {i, j};

                freqMap1[s[i]]--;
                if(freqMap1[s[i]] == 0) freqMap1.erase(s[i]);
                i++;
            }
        }

        return (res.first == -1 ? "" : s.substr(res.first, res.second - res.first + 1));
    }
};
