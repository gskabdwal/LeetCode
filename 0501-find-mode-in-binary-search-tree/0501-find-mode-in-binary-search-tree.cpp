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
    vector<int> mode;
    map<int,int> mpp;
    int mFreq = 0;
    
    vector<int> findMode(TreeNode* root) {
        if(root==NULL) return {};

        if(++mpp[root->val]>=mFreq){
            if(mpp[root->val]>mFreq)
                mode = {root->val};
            else mode.push_back(root->val);
            mFreq = mpp[root->val];
        }

        findMode(root->left);
        findMode(root->right);

        return mode;
    }
};