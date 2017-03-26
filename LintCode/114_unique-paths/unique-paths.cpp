/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: C++
@Datetime: 17-03-24 08:21
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        int dp[m][n];
        for(int j = 0; j<n; j++)
        {
            dp[0][j] = 1;
        }
        for(int i = 0; i<m; i++)
        {
            dp[i][0] = 1;
        }
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
