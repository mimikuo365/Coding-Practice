// https://leetcode.com/problems/champagne-tower/submissions/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        array<double, 100> cur = {};
        array<double, 100> next;
        cur[0] = poured;
        for (int i = 0; i < query_row; i++) {
            next = {};
            for (int j = 0; j < i + 1; j++) {
                double remain = cur[j] - 1;
                if (remain > 0) {
                    cur[j] = 1;
                    next[j] += 0.5 * remain;
                    next[j+1] += 0.5 * remain;
                }
            }
            cur = next;
        }
        if (cur[query_glass] > 1) return 1;
        else return cur[query_glass];
    }
};
