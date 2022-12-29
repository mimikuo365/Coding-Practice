// Dec 29 2022
// https://leetcode.com/problems/single-threaded-cpu/
class Solution {
public:
    struct my_comparator
    {
        // queue elements are vectors so we need to compare those
        bool operator()(vector<int> const& a, vector<int> const& b) const
        {
            if (a[0] != b[0]) return a[0] > b[0];
            else if (a[1] != b[1]) return a[1] > b[1];
            else return a[2] > b[2];
        }
    };
    using my_priority_queue = priority_queue<vector<int>, vector<vector<int>>, my_comparator>;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        my_priority_queue pq1, pq2;
        
        for (int i = 0; i < tasks.size(); i++) 
            pq1.push({tasks[i][0], tasks[i][1], i});

        long cur = 0;
        vector<int> t;
        while (!pq1.empty() || !pq2.empty()) {
            if (pq2.empty()) { // all tasks are waiting for the time -> check begin
                t = pq1.top();
                pq1.pop();
                ans.push_back(t[2]);
                if (t[0] > cur) 
                    cur = t[0];
                cur += t[1];
            }
            else { // check process time, index
                t = pq2.top(); 
                pq2.pop();
                ans.push_back(t[1]);
                if (t[2] > cur)
                    cur = t[2];
                cur += t[0];
            }
            while (!pq1.empty() && pq1.top()[0] <= cur) {
                pq2.push({pq1.top()[1], pq1.top()[2], pq1.top()[0]});
                pq1.pop();
            }
        }
        return ans;
    }
};
