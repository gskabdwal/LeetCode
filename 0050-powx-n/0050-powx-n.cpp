class Solution {
public:
    double myPow(double x, int n) {

        if(n<0){
            x = 1/x;
        }
       
        long p = labs(n);

        double res = 1.0;
        
        while(p){
            if(p&1)
                res *= x;

            x *= x;
            p >>= 1;
        }

        return res;
    }
};