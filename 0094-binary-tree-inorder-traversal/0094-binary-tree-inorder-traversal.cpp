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

    void inorder(TreeNode* root, vector<int>& ans){

        if(!root){
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }


    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        stack<TreeNode*> st;

        auto node = root;

        while(1){
            
            if(node){
                st.push(node);
                node = node->left;
            } 
            else{
                if(st.size()==0) return ans;
                auto n = st.top(); st.pop();
                ans.push_back(n->val);
                if(n->right) node = n->right;
            }

        }

        return ans;
    }
};