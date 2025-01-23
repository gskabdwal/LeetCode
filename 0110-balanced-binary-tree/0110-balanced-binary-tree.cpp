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

    int solve(TreeNode* root, int &ans ){
        
        if(!root) return 0;
        
        auto left = solve(root->left, ans);
        auto right = solve(root->right, ans);

        if(abs(left-right)>1) ans = false;

        return 1 + max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = 1;
        solve(root,ans);
        return ans;      
    }
};