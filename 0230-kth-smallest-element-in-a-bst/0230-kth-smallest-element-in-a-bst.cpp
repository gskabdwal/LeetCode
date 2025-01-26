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

    void solve(TreeNode* root, int &ans, int &cnt){
        if(ans != -1 || !root) return;

        solve(root->left,ans,cnt);

        if(--cnt==0){
            ans =  root->val; 
            return;     
        }

        solve(root->right,ans,cnt);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans= -1;
        solve(root,ans,k);

        return ans;
    }
};