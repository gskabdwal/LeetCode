class Solution {
public:
    int mod = 1e9+7;

    long long powmod(long long a, long long n){
        if(n==0) return 1;
        long long res = powmod(a,n/2)%mod;
        res = (res*res)%mod;
        if(n%2) res = (res*a)%mod;
        return res;
    }
    int countGoodNumbers(long long n) {   
        return powmod(5,n/2+n%2)*powmod(4,n/2)%mod;
    }
};