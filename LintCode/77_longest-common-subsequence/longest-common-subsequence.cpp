/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 17-03-24 12:52
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        if(A.empty() || B.empty())  return 0;
        int n = A.length();
        int m = B.length();
        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j<=m; j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(A[i-1] == B[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
