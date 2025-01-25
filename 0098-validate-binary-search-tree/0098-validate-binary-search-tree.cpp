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

    void inOrder(TreeNode * root, TreeNode* &prev, bool &ans){

        if(!ans || !root) return;

        inOrder(root->left, prev,ans);
        if(prev!=NULL){
            if(root->val<=prev->val) ans = false;
        }
        prev = root;
        inOrder(root->right,prev, ans);

    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev= NULL;    
        bool ans = true;
        inOrder(root,prev,ans);  
        return ans;
    }
};