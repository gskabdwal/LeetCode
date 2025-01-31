class Solution {
public:
    int convertTime(string current, string correct) {
        
        int h1 = stoi(current.substr(0,2))*60+stoi(current.substr(3,2));
        int h2 = stoi(correct.substr(0,2))*60+stoi(correct.substr(3,2));

        int diff = (h2-h1+24*60)%(24*60);
        
        int ans = 0;
        vector<int> ops = {60, 15, 5, 1};

        for(int x: ops){
            
            ans += diff/x; 
            diff = diff%x;
            
        }

        return ans;
    }
};