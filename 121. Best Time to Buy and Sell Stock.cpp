class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0, pre = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) pre = prices[i];
            else {
                if (pre > prices[i]) pre = prices[i]
;
                diff = max(diff, prices[i] - pre);
            }
        }
        return diff;
    }
};
