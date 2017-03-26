/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 17-03-24 04:38
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int n = triangle.size()-1;
        int m = triangle[n].size()-1;
        int dp[m];
        for (int j = 0; j <= m; j++)
        {
            dp[j] = triangle[n][j];
        }
        for (int i = n-1; i>=0; i--)
        {
            for(int j = 0; j<triangle[i].size(); j++)
            {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
