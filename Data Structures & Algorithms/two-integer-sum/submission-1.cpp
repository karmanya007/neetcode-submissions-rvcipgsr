class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            int newTarget = target - nums[i];
            if(mp.size() > 0 && mp.count(newTarget))
                return {mp[newTarget], i};

            mp[nums[i]] = i;
        }
    }
};
