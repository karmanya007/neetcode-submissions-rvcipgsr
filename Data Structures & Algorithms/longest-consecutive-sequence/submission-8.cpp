class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();    
        unordered_set<int> s;
        int res = 0;

        for(int &x : nums) s.insert(x);

        for(int &x : nums){
            if(s.count(x + 1)) continue;

            int seqLen = 1, temp = x;
            while(s.count(--temp)) seqLen++;
            res = max(res, seqLen);
        }

        return res;
    }
};
