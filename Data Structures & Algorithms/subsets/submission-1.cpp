class Solution {
    vector<vector<int>> res;

public:
    void dfs(vector<int> &nums, int i, vector<int> &temp){
        // Base case
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        // Backtrack
        temp.push_back(nums[i]);
        dfs(nums, i + 1, temp);

        temp.pop_back();
        dfs(nums, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        dfs(nums, 0, temp);

        return res;
    }
};
