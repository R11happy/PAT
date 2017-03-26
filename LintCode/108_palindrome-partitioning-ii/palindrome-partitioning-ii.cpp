/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning-ii
@Language: C++
@Datetime: 17-03-26 15:36
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n = s.size();
        bool isPalind[n][n];
        int dp[n];
        
        // for len = 1 & 2
        for(int i = 0; i<n; i++)
        {
            isPalind[i][i] = true;
            if(i+1 < n)
            {
                isPalind[i][i+1] = (s[i] == s[i+1]);
            }
        }
        
        // for len >= 3
        for (int len = 3; len <= n; ++len) {
            for (int st = 0; st <= n - len; ++st) {
                int ed = st + len - 1;
                isPalind[st][ed] = (s[st] == s[ed] && isPalind[st+1][ed-1]);
            }
        }
        
        // minimum cuts
        dp[0] = 0;
        for(int i = 1; i<n; i++)
        {
            if(isPalind[0][i])  dp[i] = 0;
            else
            {
                dp[i] = i;
                for(int j = 0; j<i; j++)
                {
                    if(isPalind[j+1][i])
                    {
                        dp[i] = min(dp[i], dp[j]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};