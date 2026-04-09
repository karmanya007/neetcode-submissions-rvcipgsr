class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        int ans;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] > nums[n - 1]) l = mid + 1;
            else{
                ans = nums[mid];
                r = mid - 1;
            }
        }

        return ans;
    }
};
