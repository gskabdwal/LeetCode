class Solution {
public:
    int longestAwesome(string s) {
        
        vector<int> dp(1024,s.size());
        dp[0] = -1;
        int mask = 0, ans = 0;
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            mask ^= (1<<(c-'0'));
            ans = max(ans, i - dp[mask]);

            for(int odd=0; odd<10;odd++){
                ans = max(ans,i-dp[(mask^(1<<odd))]);
            }

            dp[mask] = min(dp[mask],i);
        }

        return ans;
    }
};