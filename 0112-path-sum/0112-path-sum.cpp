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
    bool hasPathSum(TreeNode* root, int targetSum, int x=0) {

        if(!root){
            return false;
        }
        if(!root->left&&!root->right){
            if(x+root->val==targetSum) return true;
            return false;
        }

        return hasPathSum(root->left, targetSum, x+root->val) ||
        hasPathSum(root->right, targetSum, x+root->val); 
    }
};