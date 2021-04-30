class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> ldp(nums.size(), 0);
        vector<int> sdp(nums.size(), 0);
        int mul = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                ldp[0] = nums[0];
                sdp[0] = nums[0];
            }
            else {
                ldp[i] = max(max(nums[i] * ldp[i-1], nums[i] * sdp[i-1]), nums[i]);             
                sdp[i] = min(min(nums[i] * ldp[i-1], nums[i] * sdp[i-1]), nums[i]);
            }
            if (i == 0 || mul < ldp[i])
                mul = ldp[i];
        }
        return mul;
    }
};
