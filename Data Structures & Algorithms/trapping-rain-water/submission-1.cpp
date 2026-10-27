class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        int l = 0, r = n - 1;
        int leftMax = height[0], rightMax = height[n - 1];

        while(l < r){
            if(rightMax < leftMax){
                r--;
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
            }
            else{
                l++;
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
            }
        }

        return water;
    }
};
