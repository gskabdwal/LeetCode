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
    TreeNode* buildBST(vector<int>& nums, int l, int r){
        if(l>r) return NULL;   
        int m = (l+r)/2;
        auto node = new TreeNode(nums[m]);
        node->left = buildBST(nums,l,m-1);
        node->right = buildBST(nums,m+1,r); 
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
};