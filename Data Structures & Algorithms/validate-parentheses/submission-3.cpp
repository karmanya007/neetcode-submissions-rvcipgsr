class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        
        unordered_map<char, char> parenthesesMapping = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<int> st;
        
        for(char &c : s){
            if(!parenthesesMapping.count(c)) st.push(c);
            else{
                if(!st.size()) return false;
                if(st.top() != parenthesesMapping[c])
                    return false;
                st.pop();
            }
        }
        
        if(st.size()) return false;
        
        return true;
    }
};
