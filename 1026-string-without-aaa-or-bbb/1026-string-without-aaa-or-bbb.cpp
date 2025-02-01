class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if (B > A) return strWithout3a3b(B, A, b, a);
        while (A-- > 0) {
            res += a;
            if (A > B) res += a, A--;
            if (B-- > 0) res += b;
        }
        return res;
    }
};