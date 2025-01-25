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

    TreeNode* ins(TreeNode* root, int val){
        if(!root){
            return new TreeNode(val); 
        } 

        if(root->val < val){
            root->right = ins(root->right, val);
        }
        else if( root->val > val){
            root->left = ins(root->left, val);
        }

        return root;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return ins(root, val);
    }
};