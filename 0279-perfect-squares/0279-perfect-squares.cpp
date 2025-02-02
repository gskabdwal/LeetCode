class Solution {
public:
    int numSquares(int n) {
        
        int s= sqrt(n);
        
        if(s*s == n) return 1;

        while(n%4==0) n/=4;

        if(n%8==7) return 4;

        for(int i=1;i*i<=n; i++){

            int a = i*i;
            int b = sqrt(n-a);

            if(b*b==n-a) return 2;
        }

        return 3;
    }
};