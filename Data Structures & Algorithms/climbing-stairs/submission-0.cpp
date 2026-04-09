class Solution {
public:
    int rec(int level, int n){
        // Pruning
        if(level > n)
            return 0;
        // Base case
        if(level == n)
            return 1;

        int moves = 0;
        // Loop over all the moves
        for(int move = 1; move <= 2; move++){
            // Check if move is valid
            if(move + level <= n)
                moves += rec(level + move, n);
        }

        return moves;
    }
    int climbStairs(int n) {
        return rec(0, n);
    }
};
