class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        sort(tokens.begin(), tokens.end());
        int i= 0, ans =0,j = tokens.size()-1, score=0;
        if(j==0){
            return tokens[0]<=power;
        }
        if(tokens[0]>power) return 0;
        while(i<=j){

            if(tokens[i]<=power){
                power-= tokens[i];
                i++;
                score++;            
                ans = max(ans,score);
            }
            else if(i<j&&score>=1){
                power += tokens[j--];
                score--;
            }
            else{
                break;
            }
        }

        return ans;
    }
};