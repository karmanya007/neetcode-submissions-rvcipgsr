class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;
        priority_queue<pair<int, int>> maxHeap;
        int i = 0;
        for(int j = 0 ; j < n; j++){
            maxHeap.push({nums[j], j});
            
            if(j - i + 1 < k){
                continue;
            }

            while(!maxHeap.empty() && maxHeap.top().second <= j - k){
                maxHeap.pop();
            }

            res.push_back(maxHeap.top().first);
            i++;
        }

        return res;
    }
};
