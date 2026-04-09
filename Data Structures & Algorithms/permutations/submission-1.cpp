class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, vector<int> &perms, vector<bool> &pick){ // O(n! * n)
        if(perms.size() == nums.size()){
            res.push_back(perms);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(pick[i]) continue;

            perms.push_back(nums[i]);
            pick[i] = true;
            dfs(nums, perms, pick);

            perms.pop_back();
            pick[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perms;
        vector<bool> pick(nums.size(), false);
        dfs(nums, perms, pick);
        return res;
    }
};
