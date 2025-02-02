class Solution {

    int solve(string &s, int ind,unordered_set<string> &hs,vector<int> &dp, int ans){

        if(ind==s.size()){      
            return 1;
        }

        if(dp[ind]!=-1) return dp[ind];
        int res = 0;
        for(int j= 1; j<=2; j++){
            if(ind+j<=s.size()){
                string sub = s.substr(ind,j);
                if(hs.find(sub)!=hs.end()){
                    
                    res += solve(s,ind+j,hs,dp,ans);
                }
            }
        }
    
        return dp[ind] = res;
    }



public:
    int numDecodings(string s) {
        
        vector<int> dp(s.size(),-1);
        unordered_set<string> hs;
        for(int i=1; i<=26; i++){
            hs.insert(to_string(i));
        }
        
        return solve(s,0,hs,dp,0);

    }
};