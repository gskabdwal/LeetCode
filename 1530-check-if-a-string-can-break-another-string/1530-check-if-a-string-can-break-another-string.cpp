class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        int fl = 0;

        for(int i=0; i<s1.size(); i++){
            
            if(fl==0){
                fl = (s1[i]>=s2[i])?s1[i]==s2[i]?0:1:-1;
            }
            else if((fl==-1&&s1[i]>s2[i])||(fl==1&&s1[i]<s2[i])) return false;
            
        }


        return true;
    }
};