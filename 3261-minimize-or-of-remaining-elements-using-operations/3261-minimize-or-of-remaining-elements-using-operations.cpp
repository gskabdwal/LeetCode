class Solution {
    public:

    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans=0;
        int mask=0; // used for performing operation on prefix of bits
        for(int j=30;j>=0;j--){ // builds answer bit by bit
            mask=mask | (1<<j);// mask changes(10000.. -> 11000..->11100..->11110..->111111..)

            int cosecutiveAnd=mask;
            int mergeCount=0;// no. of merges required to make current bit 0
            for(int i:nums){
                cosecutiveAnd = cosecutiveAnd & i; 
                if((cosecutiveAnd|ans)!=ans) // explained below
                    mergeCount++; //while above condition is not achieved keep merging
                else cosecutiveAnd=mask; // else reset cosecutiveAnd to mask(11111..0000...), no need to increase count
            }

            if(mergeCount>k)
                ans|=(1<<j);// if(count is more than k, make set curent bit of 1, else it stays 0)
        }
        return ans;
    }
};