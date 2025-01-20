class Solution {

public:
    
    int seen = 0;
    int res = 0;
    
    int countArrangement(int n, int pos = -1) {
    
        if (n < 4) return n;
        if (pos == -1) pos = n;
        if (!pos) return res++;
    
        for (int i = n, bit; i; i--) {
            bit = 1 << i;
            if (!(seen & bit)  && (i % pos == 0 || pos % i == 0)) {
                // marking i as seen
                seen ^= bit;
                countArrangement(n, pos - 1);
                // backtracking
                seen ^= bit;
            }
        }
    
        return res;
    }

};