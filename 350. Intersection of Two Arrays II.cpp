class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2, ans;
        int n1=nums1.size(), n2=nums2.size();
        for (int i=0; i<n1; i++) {
            auto it = freq1.find(nums1[i]);
            if (it == freq1.end())
                freq1.insert(pair<int, int>(nums1[i], 1));
            else
                it->second++;
        }
        for (int i=0; i<n2; i++) {
            auto it = freq2.find(nums2[i]);
            if (it == freq2.end())
                freq2.insert(pair<int, int>(nums2[i], 1));
            else
                it->second++;
        }
        
        for (auto it1=freq1.begin(); it1!=freq1.end(); it1++) {
            auto it2 = freq2.find(it1->first);
            if (it2 != freq2.end())
                ans.insert(pair<int, int>(it2->first, min(it1->second, it2->second)));
        }
        
        freq1.clear();
        freq2.clear();
        vector<int> nums;
        for (auto it=ans.begin(); it!=ans.end(); it++)
            for(int i=0; i<it->second; i++)
                nums.push_back(it->first);
        ans.clear();
        return nums;
    }
};
