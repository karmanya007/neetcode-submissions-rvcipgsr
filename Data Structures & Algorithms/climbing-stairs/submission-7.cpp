class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;

        int one = 1, two = 1;
        for(int i = 2; i <= n; i++){
            int temp = one;
            one = two;
            two = temp + two;
        }

        return two;
    }
};
