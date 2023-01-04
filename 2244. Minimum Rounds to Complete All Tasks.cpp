class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (int t: tasks)
            if (m.find(t) == m.end())
                m[t] = 1;
            else
                m[t] += 1;
        int ctr = 0;
        for (auto it: m) {
            int c = it.second;
            while (c > 0) {
                if (c == 1)
                    return -1;
                else if (c % 3 == 0 || c % 2 == 1) {
                    c -= 3;
                    ctr++;
                }
                else {
                    c -= 2;
                    ctr++;
                }
            }
        }
        return ctr;
    }
};
