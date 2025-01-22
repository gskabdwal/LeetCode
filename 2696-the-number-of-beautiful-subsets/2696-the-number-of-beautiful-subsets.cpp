class Solution {

    int solve(vector<int>& nums,int k, int i, unordered_map<int,int>& st){

        if(i>=nums.size()){
            return 1;
        }

        int res = solve(nums,k,i+1,st);
        if(!st[nums[i]-k]&&!st[nums[i]+k]){
            st[nums[i]]++;
            res += solve(nums,k,i+1,st);
            st[nums[i]]--;
        }
        return res;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> hs;
        return solve(nums,k,0,hs)-1;      
    }
};