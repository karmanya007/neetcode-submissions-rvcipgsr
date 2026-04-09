class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;
        vector<vector<int>> bucket(n + 1, vector<int>());
        unordered_map<int, int> mp;

        for(int &x : nums){
            mp[x]++;
        }
        for(auto &x : mp){
            if(bucket[x.second].size()) bucket[x.second].push_back(x.first);
            else bucket[x.second] = {x.first};
        }

        for(int i = n; i > 0; i--){
            if(bucket[i].size() && k){
                for(int &x : bucket[i]) {
                    res.push_back(x);
                    k--;
                }
            }
        }

        return res;
    }
};
