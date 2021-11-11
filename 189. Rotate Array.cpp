// Challenge Day 3
// Link: https://leetcode.com/problems/rotate-array/submissions/
// Date: 2021-11-11
// Topic: Two pointers (Medium)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
