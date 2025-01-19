class Solution {

    int solve(vector<int>& nums,vector<vector<int>> &dp, int l, int r){

        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int a = nums[l] + min(solve(nums,dp,l+2,r),solve(nums,dp,l+1,r-1));
        int b = nums[r] + min(solve(nums,dp,l,r-2), solve(nums,dp,l+1,r-1));

        return dp[l][r] = max(a,b);
    }


public:
    bool predictTheWinner(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size(),-1) );
        int maxi = solve(nums,dp,0,nums.size()-1);

        if(maxi>=sum-maxi) return 1;
        return 0;
    }
};