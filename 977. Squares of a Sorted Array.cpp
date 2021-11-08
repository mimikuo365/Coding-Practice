/* 
Challenge Day 3
Topic: Two pointers
Link: https://leetcode.com/problems/squares-of-a-sorted-array/
Date: 2021-11-08

Key: 
  1. Listen to the question very carefully.
  2. Bot array are non-descending.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> square(nums.size(), 0);
        int cur = nums.size(), s = 0, e = nums.size() - 1;
        while (s <= e) {
            int square_s = nums[s] * nums[s];
            int square_e = nums[e] * nums[e]; 
            if (square_s <= square_e) {
                square[--cur] = square_e;
                e--;
            }
            else {
                square[--cur] = square_s;
                s++;
            }
        }
        return square;
    }
};
