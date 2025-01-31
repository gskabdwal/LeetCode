class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cnt =0, curFarthest = 0, curEnd = 0;

        for(int i=0;i<nums.size()-1;i++){

            curFarthest = max(curFarthest,i+nums[i]);

            if(curEnd == i){
                curEnd = curFarthest;
                cnt++;
            }
        }

        return cnt;
    }
};