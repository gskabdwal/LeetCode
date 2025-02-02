class Solution {

public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum&1) return false;
        int n = nums.size();
        int m = sum/2;
        vector<bool> prev(m+1,0), cur(m+1,0);

        prev[0] = true;

        for(int i =1; i<n; i++){

            for(int j =0; j<=m; j++){
            
                bool notTake = prev[j];
                
                bool take = false;
                if(nums[i]<=j){
                    take = prev[j-nums[i]];
                } 
            
                cur[j] = take||notTake;
                
            }
            prev = cur;
        }

        return prev[m];
    }
};