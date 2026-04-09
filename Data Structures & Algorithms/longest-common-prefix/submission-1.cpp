class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";

        n = INT_MAX;
        for(string &s : strs)
            n = min(n, (int)s.length());

        string ans = "";

        for(int curIdx = 0; curIdx < n; curIdx++){    
            char curChar = strs[0][curIdx];
            for(string &s : strs){
                if(s[curIdx] != curChar)
                    return ans;
            }
            ans += curChar;
        }

        return ans;
    }
};