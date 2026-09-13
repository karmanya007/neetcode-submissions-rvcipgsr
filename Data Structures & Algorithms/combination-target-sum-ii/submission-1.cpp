/*
    * Sort the candidates
    * The current index represents the current candidate
    * Move the index till the current candidate != next candidate
    * Choose the current candidate or don't
*/

class Solution {
    vector<vector<int>> res;
public:
    void dfs(vector<int> &candidates, int i, vector<int> &temp, int target){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i >= candidates.size() || target < 0)
            return;

        // Include
        temp.push_back(candidates[i]);
        dfs(candidates, i + 1, temp, target - candidates[i]);

        // Exclude
        temp.pop_back();
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
            i++;
        dfs(candidates, i + 1, temp, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        dfs(candidates, 0, temp, target);
        return res;
    }
};
