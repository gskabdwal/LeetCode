class Solution {
public:
    int singleNumber(vector<int>& A) {
        
        int ans = 0;
        for(int i=0; i<32; i++){
            int o = 0;
            for(int x: A){
                if(x&(1<<i)) o++;
            }

            if(o%3) ans |= (1<<i);
        }
        return ans;
    }

};