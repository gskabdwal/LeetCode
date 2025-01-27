class Solution {
public:
    typedef pair<int, int> P; // {last date before expiration, number of apples}
    int eatenApples(vector<int>& apples, vector<int>& days) {

        int ans = 0, n = apples.size();
		// min heap, the pair with the smallest expiration date is on the top
        priority_queue<P, vector<P>, greater<P>> que;
        int i = 0;
        while(i < n){
			// add today's apples
            if(i < n && apples[i] > 0) que.push({i + days[i], apples[i]});
			
			// remove outdate apples
            while(que.size() && que.top().first <= i) que.pop();
			
			// get the apple that can be eat today
            if(que.size()){
                auto p = que.top();
                que.pop();
                if(p.second > 1) que.push({p.first, p.second - 1});
                ++ans;
            }
            
            ++i;
        }

        int day = apples.size();
        while(que.size() != 0){
            auto a = que.top(); que.pop();
            if(a.first > day){
                ans += min(a.second, a.first-day);
                day = min(a.first, day + min(a.second, a.first-day));
            }
        }
        
        return ans;
    }
};