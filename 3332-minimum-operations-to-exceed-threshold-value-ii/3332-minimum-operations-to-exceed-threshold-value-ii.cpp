class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int x: nums) pq.push(x);
        int cnt = 0;
        
        
        while(pq.size()&&pq.top()<k){
            
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            cnt++;
            pq.push(min(x,y)*2+ max(x,y));
        }
        
        
        return cnt;
    }
};