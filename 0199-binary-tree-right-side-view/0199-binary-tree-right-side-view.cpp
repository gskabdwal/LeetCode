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
    
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root, int lvl = 0) {
        
        if(!root) return {};

        if(ans.size()==lvl) ans.push_back(root->val);

        rightSideView(root->right, lvl+1);
        rightSideView(root->left, lvl+1);

        return ans;
    }
};