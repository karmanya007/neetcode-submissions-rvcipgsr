class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char &x : s){
            if(x == '(' || x == '{' || x == '[') st.push(x);
            else {
                if(st.empty()) return false;
                char top = st.top();
                if(x == ')' && top != '(') return false;
                if(x == '}' && top != '{') return false;
                if(x == ']' && top != '[') return false;

                st.pop();
            }
        }

        if(st.empty()) return true;
        else return false;
    }
};
