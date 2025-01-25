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

    void inOrder(TreeNode* root, int low, int high, int &ans){

        if(root==NULL) return;
        

        inOrder(root->left,low,high,ans);
        if(root->val<=high&&root->val>=low){
            ans += root->val;
        } 
        if(root->val>high) return;
        inOrder(root->right,low,high,ans);
   
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        int ans = 0;
        inOrder(root,low,high,ans);
        return ans;
    
    }
};