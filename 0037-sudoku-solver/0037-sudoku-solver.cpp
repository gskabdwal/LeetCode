class Solution {
public:

    bool canPut(vector<vector<char>>& board, int r, int c, char num){
        
        for(int i = 0; i<9; i++){

            if(board[i][c]==num||board[r][i]==num)
                return false;
        
            int m = (r/3)*3, n = (c/3)*3;

            if(board[m+i/3][n+i%3]==num)
                return false;
        
        }


        return true;
    }


    bool solve(vector<vector<char>>& board, int r, int c){

        if(r==9) return true;
        if(c==9) return solve(board,r+1,0);
        
        if(board[r][c]!='.') return solve(board,r,c+1);

        for(int i='1'; i<='9'; i++){
            if(canPut(board,r,c,i)){                
                board[r][c] = i;
                if(solve(board,r,c+1)) 
                    return true;
                board[r][c] = '.';
            }

        }
        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board, 0,0);
    }
};