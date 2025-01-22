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

    void solve(TreeNode* root, vector<int> &ans){

        if(!root) return;

        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);

    }

    void morrisPreorder(TreeNode* root, vector<int> &nodes){
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    nodes.push_back(root->val);
                    pre -> right = root;
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    // nodes.push_back(root -> val);
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(!root) return {};

        vector<int> ans;
        // stack<TreeNode*> st;

        // auto node = root;

        // while(node){

        //     ans.push_back(node->val);
            
        //     if(node->right) st.push(node->right);
        //     node = node->left;
        //     if(!node && st.size()) node = st.top(), st.pop();

        // }

        morrisPreorder(root,ans);

        return ans;
    }
};