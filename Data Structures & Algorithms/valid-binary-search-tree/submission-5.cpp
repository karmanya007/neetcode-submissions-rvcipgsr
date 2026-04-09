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
    bool dfs(TreeNode *root, vector<int> &bounds){
        if(!root) return true;
        
        if(root->val <= bounds[0] || root->val >= bounds[1])
            return false;
        
        vector<int> leftBounds = {bounds[0], root->val};
        vector<int> rightBounds = {root->val, bounds[1]};
        return (dfs(root->left, leftBounds) && dfs(root->right, rightBounds));
    }

    bool isValidBST(TreeNode* root) {
        vector<int> bounds = {INT_MIN, INT_MAX};
        return dfs(root, bounds);    
    }
};
