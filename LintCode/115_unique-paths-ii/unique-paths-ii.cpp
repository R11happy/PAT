/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 17-03-24 08:36
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        int n = obstacleGrid[m-1].size();
        int dp[m][n];
        int flag = 0;
        for(int i = 0; i<m; i++)
        {
            if(flag == 1 || obstacleGrid[i][0] == 1) 
            {
                flag = 1;
                dp[i][0] = 0;
            }
            else dp[i][0] = 1;
        }
        flag = 0;
        for(int j = 0; j<n; j++)
        {
            if(flag ==1 || obstacleGrid[0][j] == 1)
            {
                flag = 1;
                dp[0][j] = 0;
            }
            else dp[0][j] = 1;
        }
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};