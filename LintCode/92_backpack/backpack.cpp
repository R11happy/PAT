/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 17-03-27 15:58
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        int n = A.size();
        int dp[m+1];
        //边界
        for(int v= 0; v<=m; v++)
        {
            dp[v] = 0;
        }
        for(int i = 1; i<=n; i++)
        {
            for(int v = m; v>=A[i-1]; v--)
            {
                dp[v] = max(dp[v], dp[v-A[i-1]]+A[i-1]);    //要用i-1，i不能过
            }
        }
        int maxV = 0;
        for(int v = 0; v<=m; v++)
        {
            maxV = max(maxV, dp[v]);
        }
        return maxV;
    }
};