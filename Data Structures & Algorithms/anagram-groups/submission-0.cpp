class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<char>, vector<string>> mp;

        for(string &s : strs){
            vector<char> freq(26, 0);
            for(char &c : s) freq[c - 'a']++;

            if(mp.count(freq)){
                mp[freq].push_back(s);
            }
            else {
                mp[freq] = {s};
            }
        }

        for(auto &x : mp){
            res.push_back(x.second);
        }

        return res;
    }
};
