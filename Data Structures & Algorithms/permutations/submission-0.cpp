class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) { // O(n! * n * n)
        vector<vector<int>> res = {{}};

        for(int &n : nums){ // O(n)
            vector<vector<int>> perms;
            for(auto &p : res){ // O(n!)
                for(int i = 0; i <= p.size(); i++){
                    vector<int> temp = p;
                    temp.insert(temp.begin() + i, n); // O(n)
                    perms.push_back(temp);
                }
            }
            res = perms;
        }

        return res;
    }
};
