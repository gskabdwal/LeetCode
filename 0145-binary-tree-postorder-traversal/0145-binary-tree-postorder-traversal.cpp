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

    void inorder(TreeNode* root, vector<int>& ans){

        if(!root){
            return;
        }

        inorder(root->left,ans);
        inorder(root->right,ans);
        ans.push_back(root->val);
    }

    void morrisPostorder(TreeNode* root, vector<int> &nodes){
        while (root) {
            if (root -> right) {
                TreeNode* pre = root -> right;
                while (pre -> left && pre -> left != root) {
                    pre = pre -> left;
                }
                if (!pre -> left) {
                    nodes.push_back(root -> val);
                    pre -> left = root;
                    root = root -> right;
                } else {
                    pre -> left = NULL;
                    root = root -> left;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> left;
            }
        }

        reverse(nodes.begin(),nodes.end());
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // inorder(root,ans);
        morrisPostorder(root,ans);
        return ans;
    }
};