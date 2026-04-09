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
    TreeNode* dfs1(vector<int> &preorder, unordered_map<int, int> &mp , int &preIdx, int l, int r){
        if(l > r) return nullptr;
        
        int rootVal = preorder[preIdx++];
        TreeNode *root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        
        root->left = dfs1(preorder, mp, preIdx, l, mid - 1);
        root->right = dfs1(preorder, mp, preIdx, mid + 1, r);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preIdx = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;    
        }
        
        return dfs1(preorder, mp, preIdx, 0, n - 1);
    }
};
