class Solution {

    void rec(string &s, int i, string &comb, vector<string> &ans){

        if(i>=s.size()){
            ans.push_back(comb);
            return;
        }

        if(!isdigit(s[i])){
            for(char c = s[i], cnt = 0; cnt<=2&&c>=65&&c<=132; cnt++,c += s[i]<97?32:-32){
                comb += c;
                rec(s,i+1,comb,ans);
                comb.pop_back();
            }
        }
        else{
            comb += s[i];
            rec(s,i+1,comb,ans);
            comb.pop_back();
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        string comb;
        vector<string> ans;
        rec(s,0,comb,ans);
        return ans;
    }
};