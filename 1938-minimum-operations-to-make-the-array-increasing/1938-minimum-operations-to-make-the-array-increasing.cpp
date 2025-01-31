class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int ans = 0, num = nums[0];

        for(int x: nums){
            ans += max(0,num-x);
            num = max(num,x);
            num++;
        }

        return ans;
    }
};