class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        for (int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            std::unordered_map<int, int>::iterator tmp = comp.find(nums[i]);
            if (tmp != comp.end()) 
                return vector<int> {tmp->second, i};           
            comp.insert({n, i});
        }
        return vector<int> {-1, -1};
    }
};
