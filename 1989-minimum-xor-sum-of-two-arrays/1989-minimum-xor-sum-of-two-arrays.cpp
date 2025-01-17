class Solution {
public:
    int dp[16384] = {[0 ... 16383] = INT_MAX};
    int minimumXORSum(vector<int>& a, vector<int>& b, int i = 0, int mask = 0) {
        if (i >= a.size())
            return 0;
        if (dp[mask] == INT_MAX)
            for (int j = 0; j < b.size(); ++j)
                if (!(mask & (1 << j)))
                    dp[mask] = min(dp[mask], (a[i] ^ b[j]) + minimumXORSum(a, b, i + 1, mask + (1 << j)));
        return dp[mask];
    }
};