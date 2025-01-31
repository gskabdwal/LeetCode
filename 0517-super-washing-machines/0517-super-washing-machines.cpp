class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = 0, n = machines.size();
        for (int m : machines)
            total += m;
        if (total % n) return -1;
        int target = total / n, res = 0, toRight = 0;
        for (int m : machines) {
            toRight = m + toRight - target;
            res = max(res, max(abs(toRight), m - target));
        }
        return res;
    }
};