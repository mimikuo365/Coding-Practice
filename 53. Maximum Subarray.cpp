class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur = max(cur + nums[i], nums[i]);
            if (max_sub < cur) max_sub = cur;
        }
        return max_sub;
    }
};
