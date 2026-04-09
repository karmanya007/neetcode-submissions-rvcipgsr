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
    TreeNode* dfs(vector<int> &preorder, int &preIdx, unordered_map<int, int> inorderMap, int l, int r){
        if(l > r) return nullptr;

        TreeNode *root = new TreeNode(preorder[preIdx++]);

        root->left = dfs(preorder, preIdx, inorderMap, l, inorderMap[root->val] - 1);
        root->right = dfs(preorder, preIdx, inorderMap, inorderMap[root->val] + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        int preIdx = 0;

        int n = inorder.size();
        for(int i = 0; i < n; i++)
            inorderMap[inorder[i]] = i;

        return dfs(preorder, preIdx, inorderMap, 0, n - 1);
    }
};
