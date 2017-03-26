```
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: Markdown
@Datetime: 17-03-24 05:30
```

由于智能往右或者往下走，所以dp[0][j]和dp[i][0]这一行一列都可以直接初始化
然后进行递推即可