class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, int i, int target, vector<int> &temp){
        // Base case
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i == nums.size() || target < 0)
            return;

        // Backtracking
        temp.push_back(nums[i]);
        dfs(nums, i, target - nums[i], temp);

        temp.pop_back();
        dfs(nums, i + 1, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        dfs(nums, 0, target, temp);
        return res;
    }
};
