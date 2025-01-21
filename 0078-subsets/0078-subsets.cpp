class Solution {
public:

     void recurSubsets(vector<int>& nums,int i, int n,vector<int> subset,vector<vector<int>>& ans){
         
        ans.push_back(subset);

        if(i==n){
            return;
        }

        for(int j=i; j<n;j++){
            subset.push_back(nums[j]);
            recurSubsets(nums,j+1,n,subset,ans);
            subset.pop_back();
        }

    }



    // void recurSubsets(vector<int>& nums,int i, int n,vector<int> subset,vector<vector<int>>& ans){

    //     if(i==n){
    //         ans.push_back(subset);
    //         return;
    //     }

    //     recurSubsets(nums,i+1,n,subset,ans);
    //     subset.push_back(nums[i]);
    //     recurSubsets(nums,i+1,n,subset,ans);

    // }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        for (int bit = 0; bit < (1 << n); bit++) { // Loop through all 2^n subsets
            vector<int> temp;
            for (int b = bit; b > 0; b = b & (b - 1)) { // Iterate over all set bits
                int pos = __builtin_ctz(b); // Find the position of the lowest set bit
                temp.push_back(nums[pos]);
            }
            ans.push_back(temp);
        }

        return ans;
        

        // vector<int> subset;
        // vector<vector<int>> ans;
        // recurSubsets(nums,0,nums.size(),subset, ans);

        // return ans;

    }
};