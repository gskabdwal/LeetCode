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

    void solve(TreeNode *grand){

        auto node = grand->right;

        while(node){

            if(node->left){
                auto old_node = node;
                node = node->left;
                old_node->left = node->right;
                node->right = old_node;
                grand->right = node;
            }else{
                grand = node;
                node = node->right;
            }

        }
        
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode grand;
        grand.right = root;
        solve(&grand);
        return grand.right;
    }
};