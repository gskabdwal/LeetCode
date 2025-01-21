class Solution {
public:

    void solve(int p, int k, int n,vector<int> v, vector<vector<int>> &ans){

        if(k<=0){
            if(n==0){
                ans.push_back(v);
            }
            return;
        }

        for(int i=p; i<10; i++){
            if(i<=n){
                v.push_back(i);
                solve(i+1,k-1,n-i,v,ans);
                v.pop_back();
            }
        }

    }


    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> v;
        solve(1,k,n,v,ans);
        return ans;
    }
};