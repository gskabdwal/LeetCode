class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int> pq;

        for(int x: nums) pq.push(x);

        long long ans = 0;

        while(pq.size()&&k--){
            int num = pq.top();
            pq.pop();
            ans += num;
            num = ceil(1.0*num/3);
            pq.push(num);

        }

        return ans;
    }
};