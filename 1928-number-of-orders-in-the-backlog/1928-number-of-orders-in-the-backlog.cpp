class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        typedef long long ll;
        long long sum = 0, mod = 1e9 + 7;
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> sq; // Min-heap for sell orders
        priority_queue<vector<ll>> bq; // Max-heap for buy orders

        for (auto& o : orders) {
            ll p = o[0], a = o[1], t = o[2];

            if (t == 0) {  // Buy order
                while (!sq.empty() && p >= sq.top()[0] && a > 0) {
                    int sub = min(a, sq.top()[1]);
                    auto s = sq.top();
                    sq.pop();
                    s[1] -= sub;
                    a -= sub;
                    sum = (sum - sub + mod) % mod;  // Track remaining backlog orders
                    if (s[1] > 0)
                        sq.push(s);
                }
                if (a > 0) {
                    bq.push({p, a});
                    sum = (sum + a) % mod;
                }
            } 
            else {  // Sell order
                while (!bq.empty() && p <= bq.top()[0] && a > 0) {
                    int sub = min(a, bq.top()[1]);
                    auto s = bq.top();
                    bq.pop();
                    s[1] -= sub;
                    a -= sub;
                    sum = (sum - sub + mod) % mod;  // Track remaining backlog orders
                    if (s[1] > 0)
                        bq.push(s);
                }
                if (a > 0) {
                    sq.push({p, a});
                    sum = (sum + a) % mod;
                }
            }
        }

        return sum;  // Return the total number of remaining backlog orders
    }
};
