class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> dp(10001);

        for(int x: nums) dp[x] += x;

        int take=0, skip =0;

        for(int i=0; i<10001;i++){

            int t = dp[i]+ skip;
            int s = max(skip,take);
            take = t;
            skip = s;
        }

        return max(take,skip);
    }
};