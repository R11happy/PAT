```
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: Markdown
@Datetime: 17-03-24 12:52
```

> dp[i][j]表示字符串A的i号位和字符串B的j号位之前的LCS长度

这里要注意，字符串A，B下标从0开始
但是dp下标要从1开始（dp[0][j]和dp[i][0]事先初始化为0）
1. A[i-1] == B[j-1]的时候 dp[i][j] = dp[i-1][j-1]+1
2. A[i-1] != B[j-1]的时候 dp[i][j] = max(dp[i-1][j], dp[i][j-1])