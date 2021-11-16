class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> counter(nums.size(), 0);
        vector<int> prev(nums.size(), -1);
        int max_elements = 0, max_end = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j]) == 0 && (counter[j] + 1) > counter[i]) {
                    counter[i] = counter[j] + 1;
                    prev[i] = j;
                    if (counter[i] > max_elements) {
                        max_elements = counter[i];
                        max_end = i;
                    }
                }
            }
        }
        vector<int> ans;
        while (max_end >= 0) {
            ans.push_back(nums[max_end]);
            max_end = prev[max_end];
        }
        return ans;
    }
};
