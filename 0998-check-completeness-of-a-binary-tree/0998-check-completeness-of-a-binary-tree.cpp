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

    int dfs(TreeNode *root) {
        if (!root) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if ((l & (l + 1)) == 0 && l / 2 <= r && r <= l)
            return l + r + 1;
        if ((r & (r + 1)) == 0 && r <= l && l <= r * 2 + 1)
            return l + r + 1;
        return -1 ;
    }



public:
    
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i])
            i++;
        return i == bfs.size();
    }

};