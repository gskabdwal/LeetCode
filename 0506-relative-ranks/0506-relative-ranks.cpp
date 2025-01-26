class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string> ans(score.size());
        vector<pair<int,int>> scoreindex;

        for(int i=0; i<score.size(); i++){
            scoreindex.push_back({score[i],i});
        }

        sort(scoreindex.rbegin(),scoreindex.rend());

        int rank = 1;

        for(int i=0; i<score.size(); i++){
            if(rank==1){
                ans[scoreindex[i].second] = "Gold Medal";
            }else if(rank == 2){
                ans[scoreindex[i].second] = "Silver Medal";
            }
            else if(rank == 3){
                ans[scoreindex[i].second] = "Bronze Medal";
            }
            else{
                ans[scoreindex[i].second] = to_string(rank);
            }
            rank++;
        }

        return ans;
    }
};