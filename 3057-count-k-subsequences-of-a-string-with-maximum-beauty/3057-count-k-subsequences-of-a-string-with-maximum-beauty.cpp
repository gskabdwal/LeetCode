class Solution {
public:
    long long MOD = 1e9 + 7;
    int nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = (res * (n - i)) % MOD;
            res = (res * power(i + 1, MOD - 2)) % MOD; // Using modular inverse for division
        }
        return static_cast<int>(res); // Cast the result to int before returning
    }

    long long power(int x, int n) {
        if (n == 0) return 1;
        
        long long ans = power(x, n / 2);
        ans = (ans * ans) % MOD;
        
        if (n % 2 != 0) {
            ans = (ans * x) % MOD;
        }
        
        return ans;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        map<int, int, greater<int>> mpp; // frequency -> no. of characters

        for (int i = 0; i < 26; i++) {
            int freq = -1;
            for (int j = 0; j < s.size(); j++) {
                if ((s[j] - 'a') == i)
                    freq++;
            }
            if (freq != -1)
                mpp[freq + 1]++;
        }
        int unique = 0;
        for (auto it : mpp) {
            unique += it.second;
        }
        if (unique < k) return 0;

        long long ans = 1;
        for (auto it : mpp) {
            // check if the highest freq occurrences
            if (it.second <= k) {
                ans = (ans % MOD * power(it.first, it.second) % MOD) % MOD;
                k -= it.second;
            } else {
                ans = (ans % MOD * (nCr(it.second, k) % MOD * (power(it.first, k) % MOD) % MOD) % MOD) % MOD;
                break;
            }
        }
        if (ans < 0) ans += MOD;
        return static_cast<int>(ans); // Cast the result to int before returning
    }
};