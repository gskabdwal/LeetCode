class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int orx = 0, ans = 0, j = 0;

        for(int i=0; i<nums.size(); i++){
            
            while((orx&nums[i])!=0){
                orx ^= nums[j++];
            }
            ans = max(ans, i-j+1);
            
            orx |= nums[i];

        }

        return ans;
    }
};