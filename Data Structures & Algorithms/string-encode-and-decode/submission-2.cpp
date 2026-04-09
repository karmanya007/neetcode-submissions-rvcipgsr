class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        string delim = "^";

        for(string &s : strs){
            int n = s.length();
            encodedString += to_string(n);
            encodedString += delim;
            encodedString += s;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedString = {};
        char delim = '^';
        int n = s.length();

        int i = 0, curLen;

        while(i < n){
            curLen = 0;
            while(s[i] != delim){
                curLen = curLen * 10 + (s[i++] - '0');
            }
            i++;
            string t = "";
            while(curLen--) t += s[i++];

            decodedString.push_back(t);
        }

        return decodedString;
    }
};
