class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());
        int ctr = 0;
        while (coins > 0 && !pq.empty()) {
            if (coins - pq.top() >= 0)
                ctr++;
            // cout << pq.top() << " ";
            coins -= pq.top();
            pq.pop();
        }
        return ctr;
    }
};
