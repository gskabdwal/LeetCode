class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        vector<vector<int>> cnt(26, vector<int>(26, 0));

        for(int i=0;i<votes.size();i++) {
            for(int j=0;j<votes[i].size();j++){ 
                cnt[votes[i][j]-'A'][j]++;
            }
        } 

        sort(votes[0].begin(), votes[0].end(), [&cnt](char& a, char& b) {
            for(int i=0;i<26;i++) {
                if(cnt[a-'A'][i]<cnt[b-'A'][i]) return false;
                else if(cnt[a-'A'][i]>cnt[b-'A'][i]) return true;
            }
            return a<b;
        });

        return votes[0];
    }
};