class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1e9+7;
        int mat[4][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1},
        };
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        int dp[10][n+1];
        memset(dp,0,sizeof(dp));
        // dp[i][j] : no of ways to create phone number of len j  where tha last element digit of that phone number is i;

        for(int num = 0 ; num <= 9 ; num++){
            dp[num][1] = 1;
        }

        int ans = 0;
        int dx[] = {-2,-2,+2,+2,-1,+1,-1,+1};
        int dy[] = {-1,+1,-1,+1,-2,-2,+2,+2};

        for(int len = 2 ; len <= n ; len++){
            for(int num = 0; num <= 9 ;  num++){
                int x = mp[num].first;
                int y = mp[num].second;
                for(int k = 0 ; k < 8 ; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= 0 and ny >= 0 and nx < 4 and ny < 3 and mat[nx][ny] != -1){
                        dp[num][len] += dp[mat[nx][ny]][len-1];
                        dp[num][len] %= mod;
                    }
                }
            }
        }
        
        for(int num = 0 ; num  <= 9 ; num++){
            ans += dp[num][n];
            ans %= mod;
        }
        return ans;
    }
};