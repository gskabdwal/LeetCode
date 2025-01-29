class Solution {
public:
    string clearStars(string s) {
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for(int i =0; i<s.size(); i++){
            
            if(s[i]=='*'){
                
                auto it = pq.top(); pq.pop();
                
                s[-it.second] = '*';
            }
            else{
                pq.push({s[i],-i});
            }
            
        }
        string ans;
        for(char c: s){
            if(c!='*') ans += c;
        }
        
        return ans;
    }
};