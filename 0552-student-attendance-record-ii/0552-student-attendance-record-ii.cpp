class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        int f[n + 1][2][3];

        for(int i=0; i<=1;i++){
            for(int j=0; j<=2; j++){
                f[0][i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 3; k++) {
                    int val = f[i - 1][j][2]; // ...P
                    if (j > 0) val = (val + f[i - 1][j - 1][2]) % MOD; // ...A
                    if (k > 0) val = (val + f[i - 1][j][k - 1]) % MOD; // ...L
                    f[i][j][k] = val;
                }
        return f[n][1][2];
    }
};