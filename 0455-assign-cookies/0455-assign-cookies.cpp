class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int cnt = 0;
        for(int x: s){
            if(cnt<g.size() && x>=g[cnt])
                cnt++;
        }

        return cnt;
    }
};