class Solution {
public:
    int max = 0;
    int max_x, max_y;
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        max_x = matrix.size() - 1;
        max_y = matrix[0].size() - 1;
        
        vector<vector<int>> dp (max_x+1, vector<int>(max_y+1, -1));
        findSqure(0, 0, dp, matrix);

        return max * max;
    }
    
    int findSqure(int x, int y, vector<vector<int>>&dp, vector<vector<char>>& matrix)
    {      
        if (x > max_x || y > max_y)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        
        int diag = findSqure(x+1, y+1, dp, matrix);
        int left = findSqure(x, y+1, dp, matrix);
        int up   = findSqure(x+1, y, dp, matrix);
        int value = matrix[x][y] - '0';
        
        if (x == max_x || y == max_y || diag == 0 || left == 0 || up == 0 || value == 0)
            dp[x][y] = value;
        else 
            dp[x][y] = min ({diag, left, up}) + 1;
        // cout << x << ' ' << y << ": " << dp[x][y] << endl;
        if (dp[x][y] > max)
            max = dp[x][y];
        return dp[x][y];
    }
};
