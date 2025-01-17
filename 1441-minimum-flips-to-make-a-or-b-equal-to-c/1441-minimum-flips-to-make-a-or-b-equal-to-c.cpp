class Solution {
public:
    int minFlips(int a, int b, int c) {
        
        int ans = 0;

        for(int i=0; i<30; i++){

            int cnt = 0;    
            if(a&(1<<i)) cnt++;
            if(b&(1<<i)) cnt++;
            
            ans += (c&(1<<i))?(cnt==0?1:0):cnt;    
        }

        return ans;
    }
};