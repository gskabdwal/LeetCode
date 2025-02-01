class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int cnt = 0;
        map<int,int> mpp;

        for(int x: nums) mpp[x]++;

        for(auto it: mpp){
            int x = it.first;
            while(mpp[x-1]<=0 && mpp[x]>0){
                int end = x;
                while(mpp.size()&&mpp[end]>0){
                    mpp[end]--;
                    if(mpp[end]==0) mpp[end] = -1;
                    end++;
                    if(end-x==k) break;
                } 
                if(end-x!=k) return false;
            }
        }

        return true;
    }
};