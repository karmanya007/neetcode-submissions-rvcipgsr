class Solution {
public:
    int findMin(vector<int> &nums) {
        // 1 2 3 4
        //[T T T T]

        // 3 4 5 6 1 2
        // T T T T F F

        int n = nums.size();
        int last = nums[n - 1];

        int l = 0, r = n - 1, res = INT_MAX;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] > last){
                l = m + 1;
            }
            else{
                res = min(res, nums[m]);
                r = m - 1;
            }
        }

        return res;
    }
};
