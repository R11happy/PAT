/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 17-03-24 04:20
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
