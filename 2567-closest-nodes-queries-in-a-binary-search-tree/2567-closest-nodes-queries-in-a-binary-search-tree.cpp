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


    void closest( TreeNode* root, int x, int &fl, int &ce){
        
        if(!root) return;

        if(root->val>x){
            ce = root->val;
            closest(root->left,x,fl,ce);
        }
        else if(root->val<x){
            fl = root->val;
            closest(root->right,x,fl,ce);
        }
        else{
            fl = ce = root->val;
            return;
        }
    }

public:
    vector<int> v;
    void traverse(TreeNode* n) {
        if (n != nullptr) {
            traverse(n->left);
            if (v.empty() || v.back() < n->val)
                v.push_back(n->val);
            traverse(n->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        traverse(root);
        for (int q : queries) {
            auto it = lower_bound(begin(v), end(v), q);
            if (it != end(v) && *it == q)
                res.push_back({q, q});
            else
                res.push_back({it == begin(v) ? -1 : *prev(it), it == end(v) ? -1 : *it});
        }
        return res;
    }
};