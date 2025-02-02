class Solution {
public:
    int maxSelectedElements(vector<int>& A) {
        unordered_map<int, int> dp;
        sort(A.begin(), A.end());
        int res = 0;
        for (int& a : A) {
            res = max(res, dp[a + 1] = dp[a] + 1);
            res = max(res, dp[a] = dp[a - 1] + 1);
        }
        return res;
    }
};