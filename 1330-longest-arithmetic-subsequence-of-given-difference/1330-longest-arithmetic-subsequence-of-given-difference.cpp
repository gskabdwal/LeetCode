class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 1;
        for(int x: arr){
            ans = max(ans,dp[x] = 1 + dp[x-difference]);
        }
        return ans; 
    }
};