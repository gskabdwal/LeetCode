class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=3) return n==3 || n==1;
        return n%3 ? false : isPowerOfThree(n/3);
    }
};