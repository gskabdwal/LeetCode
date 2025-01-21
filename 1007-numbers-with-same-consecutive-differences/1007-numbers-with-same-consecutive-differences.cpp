class Solution {

    void getNums(int n, int k, vector<int> &ans, int i, int num){

        if(i>=n){
            ans.push_back(num);
            return;
        }

        for(int j = (i==0?1:0) ; j<10; j++){
            if(num==0 || abs(num%10-j)==k ){
                getNums(n,k,ans,i+1, num*10+j);
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        getNums(n,k,ans,0, 0);
        return ans;
    }
};