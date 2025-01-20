class Solution {
public:
    bool isMatch(string s, string p) {
        
        int sn = s.size(), pn = p.size();

        vector<vector<int>> dp(sn+1, vector<int>(pn+1));

        dp[sn][pn] = 1;

        for(int i=sn; i>=0; i--){
            for(int j= pn-1; j>=0; j--){
                if(p[j]=='*'){
                    dp[i][j] = (i+1<=sn&&dp[i+1][j]) || dp[i][j+1];
                }
                else{
                    dp[i][j] = i+1<=sn&&dp[i+1][j+1]&&( s[i]==p[j] || p[j] == '?');
                }
            }
        }

        return dp[0][0];
    }
};