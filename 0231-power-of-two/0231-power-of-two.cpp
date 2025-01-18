class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 1) return n==1;
        return n%2 ? false : isPowerOfTwo(n/2);
    }
};