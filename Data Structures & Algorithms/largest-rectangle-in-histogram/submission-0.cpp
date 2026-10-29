class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pse(n, -1), nse(n, n);
        stack<pair<int, int>> st;
        int largestArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();

            if(!st.empty()){
                pse[i] = st.top().second;
            }

            st.push({heights[i], i});
        }

        st = {};

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top().first >= heights[i])
                st.pop();

            if(!st.empty()){
                nse[i] = st.top().second;
            }

            st.push({heights[i], i});
        }

        for(int i = 0; i < n; i++){
            largestArea = max(largestArea, heights[i] * (nse[i] - pse[i] - 1));
        }

        return largestArea;
    }
};
