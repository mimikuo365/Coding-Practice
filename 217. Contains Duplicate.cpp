class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ctr;
        for (int i = 0; i < nums.size(); i++) {
            if (ctr.find(nums[i]) != ctr.end()) return true;
            else ctr.insert(nums[i]);
        }
        return false;
    }
};
