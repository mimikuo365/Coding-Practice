class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
    	int len = 0, j = 0; // 
    	while (j < nums.size()) {
            if (j == 0 || (nums[j] != nums[len-1])) {
                nums[len] = nums[j];
                len++;
            }
            j++;
        }
        return len;
    }
};
