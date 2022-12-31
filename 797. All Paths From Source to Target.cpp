class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            for (auto n: graph[cur.back()]) {
                // cout << cur.back() << " " << n << endl;
                vector<int> tmp = cur;
                tmp.push_back(n);
                if (n == graph.size()-1) {
                    ans.push_back(tmp);
                    // cout << "Find last" << endl;
                }
                else if (graph[n].size() != 0) {
                    q.push(tmp);
                    // cout << "Have next" << endl;
                }
            }
        }
        return ans;
    }
};
