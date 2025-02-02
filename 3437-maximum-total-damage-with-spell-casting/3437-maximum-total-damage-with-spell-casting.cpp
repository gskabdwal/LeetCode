class Solution {
    
public:
    long long maximumTotalDamage(vector<int>& power) {
     
        map<int, long long> mpp;
        
        for(int x : power){
            mpp[x]++;
        }
        
        unordered_map<int,long long> dp;
        long long ans = LONG_MIN, prev, backEl;
        
        for(auto[f,s] : mpp){

            auto it = mpp.lower_bound(f-2);
            if(it!=mpp.begin()) backEl = (--it)->first;
            dp[f] = max(dp[prev],f*s+dp[backEl]);
            ans = max(ans,dp[f]);
            prev = f;
        }

        return ans;
    }
};