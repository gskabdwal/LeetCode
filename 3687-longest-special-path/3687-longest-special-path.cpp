class Solution {
   
public:
    pair<int, int> res{0, 1};
    int depth[50001] = {};
    void dfs(int i, int p, vector<vector<array<int, 2>>>& al, vector<int>& nums, int sum, int p1, int p2, vector<int> &path) {
        int prev_depth = depth[nums[i]];
        while (p1 < prev_depth)
            sum -= path[p1++];
        res = min(res, {-sum, p2 - p1});
        depth[nums[i]] = p2;
        for (auto &[j, l] : al[i])
            if (j != p) {
                path.push_back({l});
                dfs(j, i, al, nums, sum + l, p1, p2 + 1, path);
                path.pop_back();
            }
        depth[nums[i]] = prev_depth;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<array<int, 2>>> al(nums.size());
        for (const auto &e : edges) {
            al[e[0]].push_back({e[1], e[2]});
            al[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, -1, al, nums, 0, 0, 1, vector<int>() = {});
        return {-res.first, res.second};
    }
};