class Solution {
public:
    int rec(int level, int n, vector<int> &dp){
        // Pruning
        if(level > n)
            return 0;
        // Base case
        if(level == n)
            return 1;

        if(dp[level] != -1)
            return dp[level];

        int moves = 0;
        // Loop over all the moves
        for(int move = 1; move <= 2; move++){
            // Check if move is valid
            if(move + level <= n)
                moves += rec(level + move, n, dp);
        }

        return dp[level] = moves;
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return rec(0, n, dp);
    }
};
