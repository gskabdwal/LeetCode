class Solution {
public:

    long long pickGifts(vector<int>& g, int k) {
        priority_queue<int> pq(begin(g), end(g)); // Max-heap
        while (k--) {
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }

};