class Solution {
    const int base = 1337;
    
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        if(k==0) return 1;
        a %= base;
        int result = powmod(a,k/2)%base;
        result = (result*result)%base;
        if(k%2) result = (result*a)%base;
        return result;
    }

public:
    
    int superPow(int a, vector<int>& b) {
        
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    
    }
};