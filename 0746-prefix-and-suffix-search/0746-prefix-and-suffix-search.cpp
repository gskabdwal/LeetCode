class WordFilter {
public:
    unordered_map<string, int>  cnt; // key = suffix|reversed_prefix
    WordFilter(vector<string>& v) {       
        for (int idx=0; idx<v.size(); idx++) {
            const string &w=v[idx];
            int k=w.size();
            string pref="", suf;    // prefix and reversed suffix
            for (int i=0; i<k; i++) {   // for every suffix
                pref+=w[i];
                suf=pref+'|';
                for (int j=k-1; j>=0; j--) { // and rev prefix
                    suf+=w[j];
                    cnt[suf]=idx+1;
                }
            }
        }
    }    
    int f(string prefix, string suffix) {
        return cnt[prefix+'|'+(string){suffix.rbegin(), suffix.rend()}]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */