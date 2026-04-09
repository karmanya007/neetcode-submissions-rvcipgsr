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
    // Returns the max path sum without split
    int dfs2(TreeNode *root, int &res){
        if(!root) return 0;
        
        // Post order traversal
        int leftMax = max(dfs2(root->left, res), 0);
        int rightMax = max(dfs2(root->right, res), 0);
        
        // Get the max path sum with split
        res = max(res, root->val + leftMax + rightMax);
        
        return max(leftMax, rightMax) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        return max(dfs2(root, res), res);
    }
};
