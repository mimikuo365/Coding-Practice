/*
Time: 11 May 2021 (Tuesday)
Link: https://leetcode.com/problems/triangle/
Keywords: Medium, DP
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(), 0);
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = triangle[i].size()-1; j >= 0 ; j--) {
                if (j == 0)
                    dp[j] = triangle[i][j] + dp[j];
                else if (j == triangle[i].size()-1)
                    dp[j] = triangle[i][j] + dp[j-1];
                else 
                    dp[j] = triangle[i][j] + min(dp[j-1], dp[j]);
            }  
        }
        int minVal = dp[0];
        for (int i = 0; i < dp.size(); i++)
            if (minVal > dp[i])
                minVal = dp[i];
        return minVal;
    }   
};
