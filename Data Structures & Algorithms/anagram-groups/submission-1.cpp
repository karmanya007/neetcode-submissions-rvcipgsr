class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string &s : strs){
            string temp = s;

            sort(temp.begin(), temp.end());

            if(mp.count(temp)){
                mp[temp].push_back(s);
            }
            else{
                mp[temp] = {s};
            }
        }

        vector<vector<string>> res;

        for(auto x : mp){
            res.push_back(x.second);
        }

        return res;
    }
};
