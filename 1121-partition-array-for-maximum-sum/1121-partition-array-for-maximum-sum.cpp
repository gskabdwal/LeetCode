class Solution {
public:
        int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(K);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                curMax = max(curMax, A[i - k]);
                best = max(best, dp[(i - k)%K] + curMax * k);
            }
            dp[i%K] = best; 
        }
        return dp[N%K];
    }
};