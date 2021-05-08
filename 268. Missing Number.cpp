class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum = ((float)nums.size() / 2) * (nums.size()+1);
      // cout << sum;
      for (int i:nums) sum -= i;
      return sum;    
    }
};
