class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int n = nums.size();

        int prev = nums[0];
        int cur = max(nums[0],nums[1]);
        int next;
        
        for(int i=2; i<n; i++){
            next = max(cur,prev+nums[i]);
            prev = cur;
            cur = next;
        }

        return cur;
    }
};