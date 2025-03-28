class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int maxi = 1e9;
        int n = coins.size();
        vector<int> dp(amount+1,maxi);

        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0;j<n; j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }

        return dp[amount]==maxi?-1:dp[amount];
    }
};