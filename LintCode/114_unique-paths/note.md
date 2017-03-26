```
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: Markdown
@Datetime: 17-03-24 08:21
```

与【最小路径和】那题类似，也是先初始化dp[0][j]和dp[i][0]
不过这里dp[i][j]存储的是：一共有多少路径可以到达【i，j】。