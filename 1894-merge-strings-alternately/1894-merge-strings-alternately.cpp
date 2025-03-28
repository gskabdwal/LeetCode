class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int i =0, j=0, m = word1.size(), n = word2.size();
        string ans;

        while(i<m&&j<n){

            ans += word1[i++];
            ans += word2[j++];

        }

        while(i<m)  ans += word1[i++];
        while(j<n) ans += word2[j++];

        return ans;
    }
};