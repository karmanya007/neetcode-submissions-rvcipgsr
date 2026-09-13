class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &nums, vector<int> &temp, vector<bool> &isPicked){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int j = 0; j < nums.size(); j++){
            if(isPicked[j]) continue;

            // Include
            temp.push_back(nums[j]);
            isPicked[j] = true;
            dfs(nums, temp, isPicked);

            //Exclude
            temp.pop_back();
            isPicked[j] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> isPicked(nums.size(), false);
        dfs(nums, temp, isPicked);
        return res;
    }
};
