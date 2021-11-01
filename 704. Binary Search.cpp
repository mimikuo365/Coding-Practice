// Challenge Day 1
// Topic: Binary Search (Easy)
// Link: https://leetcode.com/problems/binary-search/
// Date: 2021-11-1

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int pivot = low + ((high - low) >> 1);
            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] > target)
                high = pivot - 1;
            else 
                low = pivot + 1;
        }
        return -1;
    }
};
