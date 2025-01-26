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

    pair<int,pair<int,int>> getBST(TreeNode* root, int &ans){

        if(!root) return {0,{INT_MAX,INT_MIN}};

        auto left = getBST(root->left, ans);
        auto right = getBST(root->right, ans);

        int sum = 0;
        if(root->val>left.second.second&&root->val<right.second.first){
            sum += root->val+left.first+right.first;
            ans = max(ans,sum);
            return {sum,{min(left.second.first,root->val),max(right.second.second,root->val)}};
        }
        else{
            sum +=max(left.first,right.first);
            return {sum,{INT_MIN,INT_MAX}};
        }
    }

public:
    int maxSumBST(TreeNode* root) {

        int ans = 0; 
        getBST(root,ans);       
        return ans;
    }
};