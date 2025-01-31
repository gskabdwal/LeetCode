class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
    unordered_map<int, int> pos, gap;
    for (int i = 0; i < nums.size() * 2; ++i) {
        int n = nums[i % nums.size()];
        if (pos.count(n))
            gap[n] = max(gap[n], (i - pos[n]) / 2);
        pos[n] = i;
    }
    return min_element(begin(gap), end(gap), [](const auto &p1, const auto &p2){
        return p1.second < p2.second;
    })->second;
}
};