class Solution {
    vector<int> dp;
public:
    int rec(int level, int n, vector<int> &cost){
        // Base case
        if(level >= n){
            return 0;
        }

        if(dp[level] != -1)
            return dp[level];

        // Transitions
        // Jump 1 or 2 stairs
        return dp[level] = (cost[level] + min(rec(level + 1, n, cost), rec(level + 2, n, cost)));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.resize(n, -1);

        return min(rec(0, n, cost), rec(1, n, cost));
    }
};
