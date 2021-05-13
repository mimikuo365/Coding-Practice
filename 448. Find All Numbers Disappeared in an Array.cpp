class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> find (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            find[nums[i]-1] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < find.size(); i++) {
            if (!find[i]) 
                ans.push_back(i+1);
        }
        return ans;
    }
};
