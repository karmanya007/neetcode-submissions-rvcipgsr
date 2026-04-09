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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        * THIS SHOULD WORK BUT DONT KNOW WHY IT DOESNT HERE 😵
        */
        // if(!root) return nullptr;
        // if(root == p || root == q) return root;
        
        // TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        // TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

        // if(leftLCA && rightLCA) return root; // Either p was found in left/right or q was found in right/left
        // else if(leftLCA) return leftLCA; 
        // else if(rightLCA) return rightLCA;
        // else return nullptr;
        
        if(!root || !p || !q) return nullptr;
        
        if(min(p->val, q->val) > root->val){
            return lowestCommonAncestor(root->right, p ,q);
        }
        else if(max(p->val, q->val) < root->val){
            return lowestCommonAncestor(root->left, p , q);
        }
        else{
            return root;
        }
    }
};
