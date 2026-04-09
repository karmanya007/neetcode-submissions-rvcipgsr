class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int maxLen = 0;
        for(int &n : nums) s.insert(n);

        for(int &n : nums){
            if(s.find(n - 1) == s.end()){
                int len = 1;
                int temp = n;
                while(s.find(++temp) != s.end()){
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};
