// 2:00 pm
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size(), vector<int>(2, 0));
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int i = 0; i < grid.size(); i++)
            {
                //cout << i << " " << j << " " << grid[i][j] << " ";
                if (j == 0)
                {
                    if (i == 0)
                        dp[i][1] = grid[i][j];
                    else
                        dp[i][1] = dp[i-1][1] + grid[i][j];
                }
                else
                {
                    if (i == 0)
                        dp[i][1] = dp[i][0] + grid[i][j];
                    else
                        dp[i][1] = min(dp[i-1][1], dp[i][0]) + grid[i][j];
                }
                dp[i][0] = dp[i][1];
                //cout << dp[i][1] << endl;
            }    
        }
        return dp[grid.size()-1][1];
    }
};
