class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //(y-x, x)
        deque<vector<int>> deq;
        
        int ans = INT_MIN;
        
        for(vector<int>& point : points){
            int x = point[0], y = point[1];
            
            while(!deq.empty() && x - deq.front()[1] > k){
                deq.pop_front();
            }
            
            if(!deq.empty()){
                ans = max(ans, deq.front()[0] + (y + x));
            }
            
            /*
            keep the deque decreasing(fronter element has larger y-x)
            the element before current point must have larger y-x
            */
            while(!deq.empty() && deq.back()[0] <= y - x){
                deq.pop_back();
            }
            
            deq.push_back({y-x, x});
        }
        
        return ans;
    }
};