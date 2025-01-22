class Solution {
private:
    int beautifulSubsets(vector<pair<int, int>>& s, int n, int k, int i, vector<int>& count) {
        if (i == n) {
            return 1;
        }
        if (count[i] != -1) {
            return count[i];
        }
        int skip = beautifulSubsets(s, n, k, i + 1, count);
        int take = (1 << s[i].second) - 1;
        if (i + 1 < n && s[i + 1].first - s[i].first == k) {
            take *= beautifulSubsets(s, n, k, i + 2, count);
        } else {
            take *= beautifulSubsets(s, n, k, i + 1, count);
        }
        return count[i] = skip + take;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int, map<int, int>> freq;
        for (int& x: nums) {
            freq[x % k][x]++;
        }
        for (auto& fr: freq) {
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            vector<int> count(s.size(), -1);
            result *= beautifulSubsets(s, s.size(), k, 0, count);
        }
        return result - 1;
    }
};