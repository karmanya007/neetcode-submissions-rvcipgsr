class Solution {
public:
    void dfs(vector<int> &nums, int idx, vector<vector<int>> &res, vector<int> &subset){
        if(idx == nums.size()){
            res.push_back(subset);
            return;
        }

        // Include the element
        subset.push_back(nums[idx]);
        dfs(nums, idx + 1, res, subset);

        // Don't include the element
        subset.pop_back();
        dfs(nums, idx + 1, res, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, res, subset);
        return res;
    }
};
