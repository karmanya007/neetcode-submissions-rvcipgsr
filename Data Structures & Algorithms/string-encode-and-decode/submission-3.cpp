class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for(auto &x : strs){
            s += to_string(x.length());
            s += "_";
            s += x;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0, n = s.length();
        
        while(i < n){
            int len = 0;
            while(s[i] != '_')
                len = len * 10 + (s[i++] - '0');
            i++;
            string temp = "";
            while(len--)
                temp += s[i++];
            res.push_back(temp);
        }

        return res;
    }
};
