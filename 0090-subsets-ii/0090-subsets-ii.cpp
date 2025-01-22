class Solution {
public:

    void generateSubsets(vector<int>& nums,vector<vector<int>> &ans,int ind, vector<int> subset){

        ans.push_back(subset);

        for(int i=ind; i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            subset.push_back(nums[i]);
            generateSubsets(nums,ans,i+1,subset);
            subset.pop_back();
        }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        generateSubsets(nums,ans,0,subset);

        return ans;

    }
};