class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;

        for(auto x:queries)
        {
            priority_queue<pair<string,int>> pq;

            for(int i=0;i<nums.size();i++)
            {
                int t = nums[i].length()-x[1];
                string s = nums[i].substr(t,x[1]);

                if(pq.size()<x[0])
                    pq.push({s,i});
                else
                {
                    if(pq.top().first > s)
                    {
                        pq.pop();
                        pq.push({s,i});
                    }
                }
            }
            int ind = pq.top().second;
            res.push_back(ind);
        }
        
        return res;
    }
};