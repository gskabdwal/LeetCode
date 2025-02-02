class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<uint64_t> combination(amount+1,0);

        combination[0] = 1;

        for(auto coin: coins){
            
            for(int sum = 1; sum<=amount; sum++){
                if(sum>=coin){
                    combination[sum] += combination[sum-coin];
                }
            }

        }

        return combination[amount];

    }
};