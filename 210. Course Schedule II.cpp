class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> course(numCourses, vector<int>());
        vector<int> ctr(numCourses, 0);
        vector<int> ans;
        for (int i = 0; i < p.size(); i++) {
            course[p[i][0]].push_back(p[i][1]);
            ctr[p[i][1]]++;
        }
        queue<int> q;
        for (int i = 0; i < ctr.size(); i++) {
            if (ctr[i] == 0) 
                q.push(i);
        }
        while(!q.empty()) {
            int cur = q.front();
            ans.insert(ans.begin(), cur);
            q.pop();
            for (int i = 0; i < course[cur].size(); i++) {
                ctr[course[cur][i]]--;
                if (ctr[course[cur][i]] == 0) {
                    q.push(course[cur][i]);
                }
            }
        }
        for (int i = 0; i < ctr.size(); i++)
            if (ctr[i] != 0) return {};
        return ans;
    }
};
