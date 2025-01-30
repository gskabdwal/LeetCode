class Solution {
public:
    struct xorTrie {
        static constexpr int max_b = 1 << 19;
        xorTrie *p[2] = {};
        void insert(int n) {
            xorTrie *r = this;
            for (int b = max_b; b > 0; b >>= 1) {
                int bit = (n & b) > 0;
                if (r->p[bit] == nullptr)
                    r->p[bit] = new xorTrie();
                r = r->p[bit];
            }
        }
        bool remove(int n, int b = max_b) {
            if (b == 0)
                return true;
            int bit = (n & b) > 0;
            if (p[bit] != nullptr && p[bit]->remove(n, b >> 1)) {
                delete p[bit];
                p[bit] = nullptr;
            }
            return p[0] == p[1]; // both are nullptr
        }    
        int maxXor(int n) {
            int res = 0;
            xorTrie *r = this;
            for (int b = max_b; b > 0; b >>= 1)
                if (int bit = (n & b) > 0; r->p[!bit] != nullptr) {
                    res += b;
                    r = r->p[!bit];
                }
                else
                    r = r->p[bit];
            return res;
        }  
    };
    int maximumStrongPairXor(vector<int>& nums) {
        xorTrie t;
        sort(begin(nums), end(nums));
        int i = 0, j = 0, res = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            t.insert(nums[i]);
            while (nums[j] * 2 < nums[i])
                t.remove(nums[j++]);
            res = max(res, t.maxXor(nums[i]));
        }
        return res;
    }
};