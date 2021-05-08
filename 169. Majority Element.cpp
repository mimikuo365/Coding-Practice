class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        pair<int, int> best (-1,-1);
        for (int i = 0; i < nums.size(); i++) {
            if (count.find(nums[i]) == count.end()) 
                count[nums[i]] = 1;
            else 
                count[nums[i]]++;
	        if (best.first < count[nums[i]]) { 
                best.first = count[nums[i]];
                best.second = nums[i];
            }
        }      
        return best.second;
    }
};
