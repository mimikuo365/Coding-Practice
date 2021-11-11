// Challenge Day 4
// Date: 2021-11-11
// Topic: Two pointers (Easy)
// Two methods provided here, with the second one a lot intuitive than the first one.


// Method 1 (Mine)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                while (j < nums.size() && nums[j] == 0) 
                    j++;
                if (j >= nums.size()) 
                    return;
                nums[i] = nums[j];
                nums[j] = 0;
            }
            ++i;
            ++j;
        }
    }
};

// Method 2 (LeetCode)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found. 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // After we have finished processing new elements,
        // all the non-zero elements are already at beginning of array.
        // We just need to fill remaining array with 0's.
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
