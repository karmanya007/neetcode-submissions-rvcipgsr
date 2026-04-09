class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n - 1;
        
        while(l <= r){
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) return m;
            
            // Left sorted section of the array
            if(nums[m] >= nums[l]){
                if(target > nums[m] || target < nums[l])
                    l = m + 1;
                else 
                    r = m - 1;
            }
            // Right sorted section of the array
            else {
                if(target < nums[m] || target > nums[r])
                    r = m - 1;
                else l =  m + 1;
            }
        }
        
        return -1;
    }
};
