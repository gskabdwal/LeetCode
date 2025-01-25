class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    // preorder dfs traversal
    int dfs(TreeNode* root, int cur) {
        if(!root) return 0;
        cur = cur * 10 + root -> val;                 // append current node's digit
        if(!root -> left && !root -> right)           // leaf node - return current number to be added to total sum
            return cur;
        return dfs(root -> left, cur) + dfs(root -> right, cur);   // recurse for child if current node is not leaf
    }  
};