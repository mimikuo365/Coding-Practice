class Solution {
public:
    
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[j] == 0) {
                // cout << i << " " << j << endl;
                while (i < nums.size() && (i == j || nums[i] == 0))
                    i++;
                // cout << i << " " << j << endl;
                if (i == nums.size()) return;
                if (j < i) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                i++;
            }
            else 
                j++;
        }
    }
};
