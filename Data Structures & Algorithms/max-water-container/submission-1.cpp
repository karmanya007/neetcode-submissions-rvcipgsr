class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int i = 0, j = n - 1;
        
        int curArea = 0, maxArea = 0;
        while(i < j){
            curArea = min(heights[i], heights[j]) * (j - i);
            maxArea = max(maxArea, curArea);
            
            if(heights[i] <= heights[j]) i++;
            else j--; 
        }
        
        return maxArea;
    }
};
