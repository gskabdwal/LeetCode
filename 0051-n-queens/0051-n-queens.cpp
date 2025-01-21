class Solution {

public:
    vector<int> queen;
    vector<vector<string>> ans ;

    bool check(int row , int col){
        for(int prow = 0 ;prow < row ; prow++){
            int pcol = queen[prow];
            if( (pcol==col) or  (abs(prow - row)== abs(pcol - col)) ){
                return false ;
            }
        }
        return true ;
    }

    void Nqueen(int i, int n  ){
        if(i==n){
            vector<string> temp(n,string(n,'.'));
	        for(int r = 0  ; r < queen.size() ; r++){
		        temp[r][queen[r]]='Q';	
	        }
	        ans.push_back(temp);
            return ;
        }

        for(int col = 0 ; col< n ; col++){
            if(check(i,col)){
                queen.push_back(col);
                Nqueen(i+1,n);
                queen.pop_back();
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        Nqueen(0,n);
        return ans ;
    }
};