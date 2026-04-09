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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if p == null && q == null -> true
        // if p == null || q == null -> false
        // if(p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true; // Null tree is always a subtree
        if(!root) return false; // Null RootTree and non Null tree is not a subtree
        if(isSameTree(root, subRoot)) return true; // Both trees are same
        
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
