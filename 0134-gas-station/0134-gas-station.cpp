class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size(), total = 0, cur = 0, ans= 0;

        for(int i=0; i<n; i++){
            total += gas[i] - cost[i];
            cur += gas[i]- cost[i];
            if(cur<0){
                cur = 0;
                ans = i+1;
            }
        }

        return total>=0?ans:-1;
    }
};