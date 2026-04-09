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

/*
    Balanced tree
        - Left subtree balanced
        - Right subtree balanced
    
    Balanced tree condition
        - Left height == Right height
*/

class Solution {
public:
    int dfs(TreeNode *root){
        if(!root) return 0;

        return 1 + max(dfs(root-> left), dfs(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        if(abs(leftHeight - rightHeight) > 1) 
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
