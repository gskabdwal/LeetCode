class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> hs(100001);

        for(int x: arr) hs[x]++;

        sort(hs.begin(), hs.end(),greater<int>());
        
        int i = 0, sz = arr.size();

        for(int i=0; i<100001; i++){
            sz -= hs[i];
            if(sz<=arr.size()/2) return i+1;    
        }
        return i;
    }
};