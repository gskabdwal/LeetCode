class Solution {

    void getStrings(int n, int k, int i,vector<string> &ans, char prev, string &cur){
        
        if(ans.size()>=k) return;
        
        if(i>=n){
            ans.push_back(cur);
            return;
        }

        for(char c = 'a'; c<='c'; c++){

            if(c!=prev){
                cur += c;
                getStrings(n,k,i+1,ans,c,cur);
                cur.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string cur;
        getStrings(n,k,0,ans,'&',cur);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};