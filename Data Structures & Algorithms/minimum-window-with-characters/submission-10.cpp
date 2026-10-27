class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp1, mp2;
        for(char &c : t) mp1[c]++;

        auto isWindowValid = [&]() -> bool {
            for(auto &m : mp1){
                if(mp2[m.first] < m.second) 
                    return false;
            }
            return true;
        };

        int i = 0;
        pair<int, int> res = {-1, -1};
        for(int j = 0; j < n; j++){
            mp2[s[j]]++;

            while(i <= j && isWindowValid()){
                if(res.first == -1 || (j - i + 1 < res.second - res.first + 1))
                    res = {i, j};

                mp2[s[i]]--;
                if(mp2[s[i]] == 0)
                    mp2.erase(s[i]);
                i++;
            }
        }

        return (res.first == -1) ? "" : s.substr(res.first, res.second - res.first + 1);
    }
};
