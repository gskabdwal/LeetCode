class Solution {

    class Compare {
        public:
            bool operator()(vector<int>a, vector<int> b){
                return (a[0]+a[1])>(b[0]+b[1]);
            }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>> ans;
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for(int i=0; i<nums1.size()&&i<k; i++){
            pq.push({nums1[i],nums2[0],0});
        }

        while(k--&&pq.size()){

            auto it = pq.top();
            pq.pop();

            ans.push_back({it[0],it[1]});

            if(it[2]==nums2.size()-1) continue;

            pq.push({it[0],nums2[it[2]+1],it[2]+1});

        }

        return ans;
    }
};