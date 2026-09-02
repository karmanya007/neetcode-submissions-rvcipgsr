class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };

        for(char &c : s){
            if(!mp[c]) st.push(c);
            else{
                if(st.empty()) return false;
                if(st.top() != mp[c]) return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
