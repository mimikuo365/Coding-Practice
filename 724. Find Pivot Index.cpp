class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right = reduce(nums.begin(), nums.end());
        int left = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0)
                left += nums[i-1];
            right -= nums[i];
            if (left == right)
                return i;
        }
        return -1;
    }
};
