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

    vector<vector<int>> ans;
    vector<int> v;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){
            if(targetSum==0) {{}};
            return ans;
        }

        if(root->left==NULL&&root->right==NULL){
            if(targetSum-root->val==0){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return ans;
        }

        v.push_back(root->val);
        targetSum -= root->val; 
        auto left = pathSum(root->left,targetSum);
        auto right = pathSum(root->right,targetSum);
        v.pop_back();
        
        return ans;
    }
};