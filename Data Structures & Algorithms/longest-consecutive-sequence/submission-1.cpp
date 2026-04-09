class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for(int &x : nums)
            s.insert(x);

        int n = nums.size();
        int maxLen = 0;

        for(int &x : nums){
            int temp = x;
            int curLen = 1;

            while(s.find(temp - 1) != s.end()){
                curLen++;
                temp--;
            }
            maxLen = max(maxLen, curLen);
        }

        return n ? maxLen : 0;
    }
};
