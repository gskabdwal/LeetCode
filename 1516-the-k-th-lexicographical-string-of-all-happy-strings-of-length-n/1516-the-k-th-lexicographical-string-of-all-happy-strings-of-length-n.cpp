class Solution {

    string getString(int n, int &k, int i, char prev, string &cur){

        if(i>=n){
            k--;
            return "";
        }

        for(char c = 'a'; c<='c'; c++){

            if(c!=prev){
                cur += c;
                getString(n,k,i+1,c,cur);
                if(k==0) return cur;
                cur.pop_back();
            }
        }

        return "";
    }

public:
    string getHappyString(int n, int k) {
        string cur;
        return getString(n,k,0,'&',cur);
    }
};