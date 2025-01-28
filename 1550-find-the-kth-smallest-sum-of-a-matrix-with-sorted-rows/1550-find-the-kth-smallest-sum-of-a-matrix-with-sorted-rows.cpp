class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<int>Q;
        int n = mat.size();
        for(int i=0;i<mat[0].size();i++){
            Q.push(mat[0][i]);
        }
        for(int i=1;i<n;i++){
            priority_queue<int>tmp;
            while(!Q.empty()){
                int tt = Q.top();
                Q.pop();
                for(int j=0;j<mat[i].size();j++){
                    tmp.push(tt + mat[i][j]);
                    if(tmp.size()>k){
                        tmp.pop();
                    }
                }
            }
            Q = tmp;
        }
        return Q.top();
    }
};