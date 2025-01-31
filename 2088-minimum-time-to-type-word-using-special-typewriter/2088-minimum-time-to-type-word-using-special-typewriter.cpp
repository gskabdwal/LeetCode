class Solution {
public:
    int minTimeToType(string word) {
        
        int ans = word.size();
        char prev = 'a';
        for(char c: word){
            ans += min((c-prev+26)%26,(prev-c+26)%26);
            prev = c;
        }

        return ans;
    }
};