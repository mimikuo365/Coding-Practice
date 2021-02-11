class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        vector<vector<pair<int,int>>> graph(n); 
        for (auto route: flights)
        {
            graph[route[0]].push_back(make_pair(route[2], route[1])); // Distance, goto_Node
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, K+1, src});
        while(!pq.empty())
        {
            vector<int> minN = pq.top(); pq.pop();
            if (minN[2] == dst) 
                return minN[0];
            for (auto neigh: graph[minN[2]])
            {
                if ((minN[1] - 1) >= 0) 
                    pq.push({(minN[0] + neigh.first), minN[1]-1, neigh.second});
            }
        }
        return -1;
    }
};
