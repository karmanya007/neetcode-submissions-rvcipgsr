/*
    * ( can be added till limit(n)
    * ) can be added till count(")") < count("(")
    * String is valid when count(")") == count("(")
*/

class Solution {
    vector<string> res;
public:
    void dfs(int left, int right, string &s){
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }

        if(left > 0){
            s += "(";
            dfs(left - 1, right, s);
            s.pop_back();
        }
        if(right > left){
            s += ")";
            dfs(left, right - 1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(n, n, s);
        return res;
    }
};
