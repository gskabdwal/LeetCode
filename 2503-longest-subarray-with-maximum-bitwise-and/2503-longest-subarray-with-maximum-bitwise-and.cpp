class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size(), ans = 0, cnt = 0;

        int maxi = *max_element(nums.begin(),nums.end());


        for(int i=0; i<n; i++){
            if(nums[i]==maxi){
                cnt++;
            }
            else{
                cnt = 0;
            }
            ans = max(ans,cnt);
        }
        
        return ans;
    }
};