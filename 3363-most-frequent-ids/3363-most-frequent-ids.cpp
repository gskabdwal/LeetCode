class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        map<int,long long> mpp;
        set<pair<long long,int>> st;
        vector<long long> ans(nums.size());
        
        
        for(int i=0; i<nums.size(); i++){
            
            mpp[nums[i]] += freq[i];
            auto it = st.find({mpp[nums[i]]-freq[i], nums[i]});
            if(it!=st.end()){
                st.erase(it);
            }
            
            st.insert({mpp[nums[i]],nums[i]});
            auto maxi = *st.rbegin();
            
            ans[i] = maxi.first<0?0:maxi.first;
        }
        
        return ans;
    }
};