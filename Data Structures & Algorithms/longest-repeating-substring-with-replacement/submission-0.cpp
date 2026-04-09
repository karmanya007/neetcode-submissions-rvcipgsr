class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int res = 1;
        int i = 0, j = 0;
        vector<int> v(26, 0);

        while(j < n){
            v[s[j] - 'A']++;

            if(j - i + 1 - (*max_element(v.begin(), v.end())) <= k) 
                res = max(res, j - i + 1);

            while(i < j && j - i + 1 - (*max_element(v.begin(), v.end())) > k){
                v[s[i++] - 'A']--;
            }

            j++;
        }

        return res;
    }
};
