class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n, false);
        typedef pair<int, int> pi;
        vector<vector<pi>> neighbors(n, vector<pi>());

        for (int i = 0; i < times.size(); i++) {
            neighbors[times[i][0]-1].push_back(make_pair(times[i][2], times[i][1]));
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push(make_pair(0, k));
        int val = 0;
        while (!pq.empty()) {
            pi node = pq.top();
            pq.pop();
            int len = node.first;
            int dest = node.second;
            // cout << "cur node: " << dest << " " << len << endl;
            if (!visited[dest-1]) {
                val = len;
                visited[dest-1] = true;
                for (auto j: neighbors[dest-1]) {
                    if (!visited[j.second-1]) {
                        // cout << "neigh: " << j.second << " " << j.first << endl;
                        pq.push(make_pair(j.first + len, j.second));    
                    }
                }   
            }
        }
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) return -1;
        }
        return val;
    }
};
