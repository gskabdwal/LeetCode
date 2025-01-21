class Solution {

    int getAns(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int> &hsMent, int i){

        if(i>=students.size()){
            return 0;
        }

        int ans = 0;

        for(int j=0; j<mentors.size(); j++){
            if(!hsMent[j]){
                int cnt = 0;
                for(int l=0;l<mentors[0].size(); l++){
                    cnt += students[i][l]==mentors[j][l]?1:0;
                }
                hsMent[j] ^= 1;
                ans = max(ans, cnt + getAns(students, mentors, hsMent, i+1));
                hsMent[j] ^= 1;
            }
        }     
        
        return ans;
    }

public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = mentors.size();
        vector<int> hsMent(m);
        return getAns(students, mentors, hsMent, 0);
    }
};