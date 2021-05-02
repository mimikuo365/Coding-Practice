class Solution {
public:
    int count(int n, vector<int> &dp) {
        if (n == 0)     return 1;
        else if (n < 0) return 0;
        if (dp[n] != 0) return dp[n];
        dp[n] = count(n-2, dp) + count(n-1, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return count(n, dp);
    }
};
