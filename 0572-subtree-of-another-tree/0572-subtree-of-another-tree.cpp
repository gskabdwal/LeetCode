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

    string computeHash(TreeNode *root, unordered_map<TreeNode*, string> &hash){
        if(!root)
        return "#";

        string leftHash=computeHash(root->left, hash);
        string rightHash=computeHash(root->right, hash);

        hash[root]='*'+to_string(root->val)+'*'+leftHash+rightHash;
        return hash[root];
    }

    bool isSame(TreeNode* root, TreeNode* subRoot, unordered_map<TreeNode*, string> &hash){
        if(!root and !subRoot)
        return true;

        if(!root or !subRoot)
        return false;

        if(hash[root]==hash[subRoot])
        return true;

        return isSame(root->left, subRoot, hash) or isSame(root->right, subRoot, hash);;
    }

  public:

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //O(S+T) soln using idea that preorder traversal of any tree involving NULL is 
        //always unique
        if(!root and !subRoot)
        return true;

        if(!root or !subRoot)
        return false;

        unordered_map<TreeNode*, string> hash;

        computeHash(root, hash);
        computeHash(subRoot, hash);

        return isSame(root, subRoot, hash);
    }
};