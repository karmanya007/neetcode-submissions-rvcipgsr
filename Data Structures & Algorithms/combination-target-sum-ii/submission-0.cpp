class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int> &candidates, int target, int i, vector<int> &cur, int total) {
        if(total == target){
            res.push_back(cur);
            return;
        }
        if(total > target || i >= candidates.size()){
            return;
        }

        // Include cur element
        cur.push_back(candidates[i]);
        dfs(candidates, target, i + 1, cur, total + candidates[i]);

        // Exclude cur and the subsequent same element/s
        cur.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;
        dfs(candidates, target, i + 1, cur, total);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }
};
