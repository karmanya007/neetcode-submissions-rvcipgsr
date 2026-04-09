class Solution {
public:

    string encode(vector<string>& strs) {
    int n = strs.size();
    string delim = "*";

    string encodedString = "";
    for(int i = 0; i < n; i++){
        encodedString += to_string(strs[i].length());
        encodedString += delim;
        encodedString += strs[i];
    }

    return encodedString;
}

vector<string> decode(string s) {
    int n = s.length();

    if(n == 0) return {};

    int i = 0, curLen = 0;
    vector<string> res;
    while(i < n){
        curLen = 0;
        while(s[i] != '*'){
            curLen = curLen * 10 + (s[i++] - '0');
        }
        i++;
        string temp = "";
        while(curLen--) temp += s[i++];
        res.push_back(temp);
    }

    return res;
}
};
