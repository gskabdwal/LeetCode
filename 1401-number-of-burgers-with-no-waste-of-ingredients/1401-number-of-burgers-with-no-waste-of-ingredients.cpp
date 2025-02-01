class Solution {
public:
    vector<int> numOfBurgers(int tS, int cS) {
        
        if(tS%2 || tS<2*cS || tS>4*cS) return {};
        
        int b =  (4*cS-tS)%2?0:(4*cS-tS)/2;
        return {cS-b,b};
    }
};