class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int lim) {
        
        vector<int> hash(32);
        int sum = 0, j=0, ans = INT_MAX;
        for(int i=0; i< nums.size(); i++){
            sum |= nums[i];
            int y = nums[i];
            for(int k= 30; k>=0; k--){
                if(y&(1<<k)){
                    hash[k] += 1;
                }
            }
            
            while((j<=i)&& (sum >= lim)){
                
                ans = min(ans,i-j+1);
                
                int x= nums[j++];
                
                for(int k= 30; k>=0; k--){
                    if(x&(1<<k)){
                        hash[k] -= 1;
                        if(hash[k]==0) sum -= (1<<k);
                    }
                }
                if(sum<lim) break;
            }
            
        }
        
        return ans==INT_MAX?-1:ans;
    }
};