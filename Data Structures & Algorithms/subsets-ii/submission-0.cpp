class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, vector<int> &subset, int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, subset, i + 1);

        subset.pop_back();
        while(i < nums.size() - 1 && nums[i] == nums[i + 1])
            i++;
        dfs(nums, subset, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(nums, subset, 0);
        return res;
    }
};
