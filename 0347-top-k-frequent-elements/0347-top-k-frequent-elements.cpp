class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        
        vector<int> res;
        // pair<first, second>: first is frequency,  second is number
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq; 
        for(auto it = map.begin(); it != map.end(); it++){
            pq.push({it->second, it->first});
            if(pq.size() >k){
                pq.pop();
            }

        }

        while(pq.size()!=0){

            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};