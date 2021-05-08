class Solution {
private:
    int countRoute(vector<vector<int>>& dp, int m, int n) {
        if (dp[m][n] != -1)
            return dp[m][n];
        else if (m == 0 || n == 0)
            dp[m][n] = 1;
        else
            dp[m][n] = countRoute(dp, m-1, n) + countRoute(dp, m, n-1);
        return dp[m][n];
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countRoute(dp, m-1, n-1);
    }
};
