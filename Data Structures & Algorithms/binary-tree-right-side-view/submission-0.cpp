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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *rightNode = nullptr;
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode *curNode = q.front();
                q.pop();

                if(curNode){
                    rightNode = curNode;
                    if (curNode->left)  q.push(curNode->left);
                    if (curNode->right) q.push(curNode->right);
                }
            }

            if(rightNode)
                res.push_back(rightNode->val);
        }

        return res;
    }
};
