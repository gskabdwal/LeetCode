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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &ind, int l , int r){

        if(l>r) return NULL;
        int p = l;
        while(inorder[p]!=postorder[ind]) p++;
        //cout<<inorder[p]<<endl;
        ind--;
        auto root = new TreeNode(inorder[p]);

        root->right = build(inorder, postorder, ind, p+1, r);
        root->left = build(inorder,postorder, ind, l,p-1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ind = postorder.size()-1;
        return build(inorder, postorder, ind, 0, inorder.size()-1);

    }
};