class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        queue<unordered_set<int>> visited;
        queue<int> q;
        vector<vector<int>> neigh(grid.size() * grid[0].size(), vector<int>{});

        int adjacent_val[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int e, total_block = 0;
        int col_size = grid[0].size();

        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[i].size(); j++) {
                int cur = i * col_size + j; 
                if (grid[i][j] != -1)
                    total_block += 1;

                for (int a = 0; a < 4; a++) {
                    int n_i = i + adjacent_val[a][0];
                    int n_j = j + adjacent_val[a][1];
                    if (n_i >= 0 && n_i < grid.size() && n_j >= 0 && n_j < grid[0].size() && grid[n_i][n_j] != -1) {
                        int val = n_i * col_size + n_j;
                        neigh[cur].push_back(val);
                    }
                }
                    
                if (grid[i][j] == 1) {
                    q.push(cur);
                    unordered_set<int> set;
                    set.insert(cur);
                    visited.push(set);
                }
                else if (grid[i][j] == 2)
                    e = cur;
            }

        int counter = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            unordered_set<int> set = visited.front(); 
            visited.pop();

            for (auto n: neigh[t]) {
                if (set.find(n) == set.end() && n == e && set.size() == total_block-1) {
                    counter += 1;
                }
                else if (set.find(n) == set.end()) {
                    unordered_set<int> tmp = set;
                    tmp.insert(n);
                    visited.push(tmp);
                    q.push(n);
                }
            }
        }
        return counter;

    }
};
