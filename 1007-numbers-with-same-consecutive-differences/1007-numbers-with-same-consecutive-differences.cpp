class Solution {

    void getNums(int n, int k, vector<int> &ans, int i, int num){

        if(i>=n){
            ans.push_back(num);
            return;
        }

        int dig = num%10;
        
        if(dig+k<=9) getNums(n,k,ans,i+1,num*10+dig+k);
        if(k!=0 && dig>=k) getNums(n,k,ans,i+1,num*10+dig-k);

    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int num = 1 ; num<10; num++)
            getNums(n,k,ans,1, num);
        return ans;
    }
};