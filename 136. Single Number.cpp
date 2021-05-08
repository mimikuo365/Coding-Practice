class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> counter;
        for (int i : nums) {
            if (counter.find(i) != counter.end()) counter.erase(i);
            else counter.insert(i);
        }
        unordered_set<int>::iterator it = counter.begin();
        return *it;
    }
};
