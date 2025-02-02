class Solution {
public:
        int longestArithSeqLength(vector<int>& A) {
        int res = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)  {
                int d = A[i] - A[j] + 500;
                dp[i][d] = max(2, dp[j][d] + 1);
                res = max(res, dp[i][d]);
            }
        return res;
    }
};