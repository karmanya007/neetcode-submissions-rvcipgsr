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
    TreeNode* dfs(vector<int> &preorder, unordered_map<int, int> &inorderMp, int &preIdx, int l, int r){
        if(l > r) return nullptr;
        int inorderIdx = inorderMp[preorder[preIdx]];
        TreeNode *root = new TreeNode(preorder[preIdx++]);

        root->left = dfs(preorder, inorderMp, preIdx, l, inorderIdx - 1);
        root->right = dfs(preorder, inorderMp, preIdx, inorderIdx + 1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMp;
        int preIdx = 0;

        for(int i = 0; i< inorder.size(); i++) 
            inorderMp[inorder[i]] = i;

        return dfs(preorder, inorderMp, preIdx, 0, inorder.size() - 1);
    }
};
