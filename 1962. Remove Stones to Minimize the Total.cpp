# Dec 28 2022

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (auto e: piles)
            pq.push(e);

        for (int i = 0; i < k; i++) {
            int t = pq.top();
            pq.pop();
            t = (t+1) / 2;
            pq.push(t);
        }
        
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
