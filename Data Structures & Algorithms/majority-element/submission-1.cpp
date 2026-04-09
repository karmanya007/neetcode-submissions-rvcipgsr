class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int curEl = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(curEl == nums[i]){
                count++;
            }
            else{
                count--;
                if(count <= 0){
                    curEl = nums[i];
                }    
            }
        }

        return curEl;
    }
};