class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1, cur = 1;

        for(int i=2;i<=n;i++){

            int next = prev+cur;
            prev = cur;
            cur = next;

        }
        return cur;
    }
};