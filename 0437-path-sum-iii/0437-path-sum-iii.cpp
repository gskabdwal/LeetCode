class Solution {

    void helper(TreeNode *p, long long cur, int sum, long long &total, unordered_map<long long, long long> &m) {
        if (!p) return;
        
        cur += p->val;
        if (m.find(cur - sum) != m.end()) total += m[cur - sum];
        m[cur]++;
        
        helper(p->left, cur, sum, total, m);
        helper(p->right, cur, sum, total, m);
        
        m[cur]--;
    }

public:

    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, long long> m;
        m[0]++;
        
        long long total = 0;
        helper(root, 0, sum, total, m);
        return total;
    }
    
};