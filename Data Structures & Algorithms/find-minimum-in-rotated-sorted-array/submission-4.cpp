class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        
        int lastEl = nums[n - 1];
        
        int l = 0, r = n - 1, res = 1000;
        while(l <= r){
            int m = l + (r - l) / 2;
            
            if(nums[m] <= lastEl){
                res = min(res, nums[m]);
                r = m - 1;
            }
            else 
                l = m + 1;
        }
        
        return res;
    }
};
