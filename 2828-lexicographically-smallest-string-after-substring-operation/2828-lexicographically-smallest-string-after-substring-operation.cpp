class Solution {
public:
    string smallestString(string s) {
        
        int flipped = 0;

        for(int i=0; i<s.size(); i++){
            if(flipped&&s[i]=='a'){
                return s;
            }
            if((i==s.size()-1&&flipped==0)||s[i]!='a'){
                flipped = 1;
                s[i] = ((s[i]-'a')-1+26)%26+'a';
            } 
        }

        return s;
    }
};