class Solution {
public:

    void getAll(vector<int>& candidates, int target,  vector<vector<int>> &ans, int ind, vector<int> subset){
        
        if(target==0){
            ans.push_back(subset);
            return;
        }

        for(int i = ind; i<candidates.size(); i++){

            if(ind<i&&candidates[i]==candidates[i-1]) continue;

            if(target<candidates[ind]) break;

            subset.push_back(candidates[i]);
            getAll(candidates,target-candidates[i],ans,i+1,subset);
            subset.pop_back();
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        getAll(candidates,target,ans,0,subset);
        return ans;
    }
};