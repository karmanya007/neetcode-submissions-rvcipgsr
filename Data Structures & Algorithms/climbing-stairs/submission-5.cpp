class Solution {
public:
    int rec(int level, int n, vector<int> &dp){
        if(level > n)
            return 0;
        if(level == n)
            return 1;
        if(dp[level] != -1)
            return dp[level];

        int moves = 0;
        moves += rec(level + 1, n, dp);
        moves += rec(level + 2, n, dp);

        return dp[level] = moves;
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return rec(0, n, dp);
    }
};
