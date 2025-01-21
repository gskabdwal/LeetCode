class Solution {
public:

    void getAll(vector<int>& candidates, int target,  vector<vector<int>> &ans,int i,vector<int> subset){

        if(i==candidates.size()){
            if(target==0)
                ans.push_back(subset);
            return;
        }
        if(target < 0) return;

        if(candidates[i]<=target){
            subset.push_back(candidates[i]);
            getAll(candidates,target-candidates[i],ans,i, subset); 
            subset.pop_back();
        }
        
        getAll(candidates,target,ans,i+1, subset);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        getAll(candidates,target,ans,0,subset);
        return ans;
    }
};