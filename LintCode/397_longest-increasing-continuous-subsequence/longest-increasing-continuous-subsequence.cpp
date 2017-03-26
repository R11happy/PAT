/*
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 17-03-24 09:01
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int n = A.size();
        int dpI[n];
        int dpD[n];
        for(int i = 0; i<n; i++)
        {
            dpI[i] = 1;
            dpD[i] = 1;
        }
        for(int i= 1; i<n; i++)
        {
            if(A[i-1] < A[i])
            {
                dpI[i] = max(dpI[i], dpI[i-1]+1);
            }
            else if(A[i-1] > A[i])
            {
                dpD[i] = max(dpD[i], dpD[i-1]+1);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            ans = max(dpI[i], ans);
            ans = max(dpD[i], ans);
        }
        return ans;
    }
};