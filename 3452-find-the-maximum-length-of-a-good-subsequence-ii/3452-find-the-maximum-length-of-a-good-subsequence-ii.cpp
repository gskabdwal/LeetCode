class Solution {
public:
    int maximumLength(vector<int>& A, int k) {
        vector<unordered_map<int, int>> dp(k + 1);
        vector<int> res(k + 1);
        for (int a : A) {
            for (int i = k; i >= 0; --i) {
                dp[i][a] = max(dp[i][a] + 1, (i > 0 ? res[i - 1] + 1 : 0));
                res[i] = max(res[i], dp[i][a]);
            }
        }
        return res[k];
    }
};