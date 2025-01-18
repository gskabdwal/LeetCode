class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=4) return n==4 || n==1;
        return n%4 ? false : isPowerOfFour(n/4);
    }
};