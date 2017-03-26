/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: C++
@Datetime: 17-03-24 12:12
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int n = nums.size();
        int dp[n];
        for(int i = 0; i<n; i++)
        {
            dp[i] = 1;
        }
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] ) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
