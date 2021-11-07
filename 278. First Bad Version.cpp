// Challenge Day 2
// Topic: Binary Search (Easy)
// Link: https://leetcode.com/problems/binary-search/
// Date: 2021-11-07

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int high = n, low = 1;
        while (high >= low) {
            int pivot = ((high - low) >> 1) + low;
            if (isBadVersion(pivot))
                high = pivot - 1;
            else
                low = pivot + 1;
        }
        return low;
    }
};
