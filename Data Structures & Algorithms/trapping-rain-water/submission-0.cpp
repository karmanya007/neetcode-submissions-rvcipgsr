class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int maxWaterArea = 0;
        int l = 0, r = n - 1;
        int maxLeftHeight = height[l], maxRightHeight = height[r];

        // Water in the ith column = min(leftMaxHeight, rightMaxHeight) - height[i]
        while(l < r){
            // This if-else is the min(leftMaxHeight, rightMaxHeight)
            if(maxLeftHeight < maxRightHeight){
                l++;
                maxLeftHeight = max(maxLeftHeight, height[l]);
                maxWaterArea += maxLeftHeight - height[l];
            }
            else{
                r--;
                maxRightHeight = max(maxRightHeight, height[r]);
                maxWaterArea += maxRightHeight - height[r];
            }
        }

        return maxWaterArea;
    }
};
