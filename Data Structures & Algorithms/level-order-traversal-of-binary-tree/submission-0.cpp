/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> res;
        
        while(!q.empty()){
            vector<int> curLevel;
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                TreeNode *node = q.front();
                q.pop();
                
                if(!node) continue;
                
                curLevel.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            
            if(curLevel.size()) res.push_back(curLevel);
        }
        
        return res;
    }
};
