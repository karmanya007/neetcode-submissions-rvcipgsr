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
    int dfs1(TreeNode *root, int &k){
        if(!root) return INT_MAX;
        
        int leftVal = dfs1(root->left, k);
        if(k-- == 1) return root->val;
        int rightVal = dfs1(root->right, k);
        
        return min(leftVal, rightVal);
    }

    int kthSmallest(TreeNode* root, int k) {
        return dfs1(root, k);
    }
};
