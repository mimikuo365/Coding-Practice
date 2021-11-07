// Challenge Day 2
// Topic: Binary Search (Easy)
// Link: https://leetcode.com/problems/search-insert-position/
// Date: 2021-11-07


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int pivot = low + ((high - low) >> 1);
            if (nums[pivot] < target)
                low = pivot + 1;
            else if (nums[pivot] > target)
                high = pivot - 1;
            else
                return pivot;
        }
        return low;
    }
};
