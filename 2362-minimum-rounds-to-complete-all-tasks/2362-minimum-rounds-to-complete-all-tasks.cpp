class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int ans = 0;
        map<int,int> mpp;

        for(int x: tasks){
            mpp[x]++;
        }    

        for(auto it: mpp){
            int x = it.second;
            if(x==1) return -1;
            ans += x/3;
            x %= 3;
            ans += x==1?1:x/2;
        }

        return ans;
    }
};