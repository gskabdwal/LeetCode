class Solution {
public:
    struct bitTree {
        bitTree* p[2] = {};
        void insert(int num, int bit) {
            if (bit > 0) {
                auto res = (num & bit) > 0;
                if (p[res] == nullptr)
                    p[res] = new bitTree();
                p[res]->insert(num, bit / 2);
            }
        }
        int getMax(int xi, int mi, int bit, int bitSum) {
            if (bitSum > mi)
                return INT_MIN;            
            if (bit == 0)
                return 0;
            if (p[0] == nullptr)
                return ((xi & bit) ? 0 : bit) + p[1]->getMax(xi, mi, bit / 2, bitSum + bit);
            if (p[1] == nullptr)
                return ((xi & bit) ? bit : 0) + p[0]->getMax(xi, mi, bit / 2, bitSum);
            int pos = (xi & bit) == 0; // preferred path.
            int res = bit + p[pos]->getMax(xi, mi, bit / 2, bitSum + pos * bit);
            if (res < 0) // preferred choice numbers are too large.
                res = p[!pos]->getMax(xi, mi, bit / 2, bitSum + !pos * bit);
            return res;
        }
    };
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qs) {
        int max_mi = 0;
        for (auto &q : qs)
            max_mi = max({max_mi, q[0], q[1]});
        int bits = 1 << (int)log2(max_mi);
        bitTree root;
        for (auto n : nums)
            root.insert(n, bits);
        vector<int> res;
        for (auto &q : qs) {
            auto max = root.getMax(q[0], q[1], bits, 0);
            res.push_back(max < 0 ? -1 : max);
        }
        return res;
    }
};