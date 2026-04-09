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
    void maxInBT(TreeNode* node, int &maxVal) {
        if (!node) return;

        maxVal = max(maxVal, node->val);
        maxInBT(node->left, maxVal);
        maxInBT(node->right, maxVal);
    }

    void minInBT(TreeNode* node, int &minVal) {
        if (!node) return;

        minVal = min(minVal, node->val);
        minInBT(node->left, minVal);
        minInBT(node->right, minVal);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        int maxLeft = -1001, minRight = 1000;
        maxInBT(root->left, maxLeft);
        minInBT(root->right, minRight);
        
        return isValidBST(root->left) && 
        isValidBST(root->right) && 
        maxLeft < root->val && 
        minRight > root->val;
    }
};
