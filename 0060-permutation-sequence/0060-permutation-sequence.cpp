class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s;
        long long fact = 1; 

        for(int i=1;i<n; i++){

            s += (i+'0');
            fact *= i;
        }

        s += (n+'0');

        k--;
        string ans;

        while(s.size()!=1){

            int ind = k/fact;
            ans += s[ind];

            s.erase(s.begin()+ind);

            k = k%fact;
            fact /= s.size(); 
        }

        ans += s[0];

        return ans;
    }
};