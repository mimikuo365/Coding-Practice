class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
//         unordered_map<int> numMap;
//         for(int i = 0; i < nums.size(); ++i){
//             numMap[nums[i]] = 1;
//         }
        
        for(int i = 0; i < nums.size(); ++i){
            int low = i+1;
            int high = nums.size()-1;
            if(i == 0 || nums[i-1] != nums[i]){
                while(low < high){
                    int sum = nums[low] + nums[high] + nums[i];
                    if(sum > 0) --high;
                    else if (sum < 0) ++ low;
                    else{
                        vector<int> temp = {nums[i], nums[low], nums[high]};
                        res.push_back(temp);
                        ++low;
                        --high;
                        while(low < high && nums[low] == nums[low-1]){
                            ++low;
                        }
                    }
                }
            }
            
        }
        return res;
        
    }
};
