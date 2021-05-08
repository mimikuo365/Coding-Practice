class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        else {
        int i = m+n-1, j = n-1, a = m-1;
        while(i >= 0) {
            if (a >= 0 && j >= 0) nums1[i] = max(nums1[a], nums2[j]);  
            else if (a >= 0) nums1[i] = nums1[a];
            else nums1[i] = nums2[j]; 	
            if (a >= 0 && nums1[i] == nums1[a]) a--;
            else j--;
            i--;
            }
        }
    }
};
