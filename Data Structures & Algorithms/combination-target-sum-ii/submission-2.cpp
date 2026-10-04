class Solution {
    vector<vector<int>> res;
public:
    void dfs(int i, vector<int> temp, vector<int>& candidates, int target){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i == candidates.size() || target < 0)
            return;

        // Choose
        temp.push_back(candidates[i]);
        dfs(i + 1, temp, candidates, target - candidates[i]);

        // Don't choose
        temp.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;

        dfs(i + 1, temp, candidates, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(0, temp, candidates, target);
        return res;
    }
};
