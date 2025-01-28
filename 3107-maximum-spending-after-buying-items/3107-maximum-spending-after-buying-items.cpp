class Solution {
public:
    #define ELEMENT tuple<int, int, int>
    // time/space: O(mn * log(m))/O(m)
    long long maxSpending(vector<vector<int>>& values) {
        int m = values.size(), n = values[0].size();
        priority_queue<ELEMENT, vector<ELEMENT>, greater<ELEMENT>> pq;

        // push the rightmost available item `j` for each shop `i`
        for (int i = 0; i < m; i++) pq.push({values[i][n - 1], i, n - 1});
        
        // buy the cheaper item eariler
        long long sum = 0LL;
        long long day = 1LL;
        while (!pq.empty()) {
            auto [value, i, j] = pq.top();
            pq.pop();
            sum += ((long long)(value) * (day++));
            if (j > 0) pq.push({values[i][j - 1], i, j - 1});
        }
        return sum;
    }
};