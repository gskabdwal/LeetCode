class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        int total = 0, res = 0, min2 = 123456, max2 = -123456, n = A.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = A[i], b = A[i + 1];
            total += abs(a - b);
            res = max(res, abs(A[0] - b) - abs(a - b));
            res = max(res, abs(A[n - 1] - a) - abs(a - b));
            min2 = min(min2, max(a, b));
            max2 = max(max2, min(a, b));
        }
        return total + max(res, (max2 - min2) * 2);
    }
};