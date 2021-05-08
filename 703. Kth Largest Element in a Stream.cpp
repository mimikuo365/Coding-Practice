class KthLargest {
private: 
    int greatest_k;
    vector<int> sorted;

public:
    KthLargest(int k, vector<int>& nums) 
    {
        sorted = nums;
        sort(sorted.begin(), sorted.end(), greater<int>());
        greatest_k = k;
    }
  
    int add(int val) 
    {
        std::vector<int>::iterator up; 
        up = upper_bound(sorted.begin(), sorted.end(), val, [](int a, int b) { return a >= b; });
        sorted.insert (up, val);
        return sorted[greatest_k-1];
    }
};




/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
