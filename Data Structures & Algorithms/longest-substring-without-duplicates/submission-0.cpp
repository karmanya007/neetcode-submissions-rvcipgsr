class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int res = 0;
        int i = 0, j = 0;
        unordered_map<char, int> mp;

        while(j < n){
            mp[s[j]]++;

            if(mp.size() == (j - i + 1))
                res = max(res, j - i + 1);

            while(i < j && mp.size() < (j - i + 1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            j++;
        }

        return res;
    }
};
