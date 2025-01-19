class Solution {
    int mod = 1e9+7;

    long long binpow(long long a, long long n){
        if(n==0) return 1;
        a %= mod;
        long long res = binpow(a,n/2)%mod;
        res = (res*res)%mod;
        if(n%2) res = (res*a)%mod;
        return res;
    }

public:

    int minNonZeroProduct(int p) {
        long long ans = (1ll<<p) - 1;
        ans = (ans%mod*binpow(ans-1,ans/2))%mod;
        return ans;
    }
};