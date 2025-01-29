class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<vector<int>> pro;

        for(int i=0; i<capital.size(); i++){
            pro.push_back({capital[i],profits[i]});
        }
        priority_queue<int> pq;
        sort(pro.begin(),pro.end());
        int i = 0;
        while(k--){

            while(i<capital.size()&&pro[i][0]<=w){
                pq.push(pro[i][1]);
                i++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();

        }

        return w;
    }
};