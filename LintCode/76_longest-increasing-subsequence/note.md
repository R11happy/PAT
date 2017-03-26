```
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/longest-increasing-subsequence
@Language: Markdown
@Datetime: 17-03-24 12:12
```

初始化后遍历数组nums[i]，分别以nums[i]作为结束数字，放在前边哪一个数字后面可以组成更长的子串。然后不断更新获得最长子串。