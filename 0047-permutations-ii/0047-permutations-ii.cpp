class Solution {

    void solve(vector<int> nums,int ind,vector<vector<int>> &ans){

        if(ind==nums.size()-1){  
            ans.push_back(nums);
            return;
        } 

        for(int i=ind; i<nums.size(); i++){
            if(i!=ind && nums[i]==nums[ind]) continue;
            swap(nums[ind], nums[i]);
            solve(nums,ind+1,ans);
            //swap(nums[ind], nums[i]);

        }

    }



public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        solve(nums, 0, ans);

        return ans;
    }
};