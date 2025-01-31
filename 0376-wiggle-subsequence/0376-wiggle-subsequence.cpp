class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int peak = 1, valley = 1;

        for(int i=1; i<nums.size(); i++){

            if(nums[i]-nums[i-1]>0) peak = valley + 1;
            else if(nums[i]-nums[i-1]<0) valley = peak + 1;
        } 

        return max(peak,valley);
    }
};