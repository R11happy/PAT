```
@Copyright:LintCode
@Author:   R11happy
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning-ii
@Language: Markdown
@Datetime: 17-03-26 15:36
```

为了提高递推的效率，可以先进行预处理：开一个bool数组isPalind，isPalind[i][j]表示字符串i到j是否是回文串。判断一个字符串是否是回文串可以O(n)完成，计算这个数组也可以用DP的思想，isPalind[i][j]是回文串当且仅当s[i] = s[j]并且isPalind[i+1][j-1] = true。所以计算isPalind需要O(n^2)。

定义f[i]表示对前i个字符组成的子串进行回文分割所需要的最少次数。则有如下递推关系：
f[i] = 0, 当isPalind[0][i] = true
f[i] = min { f[j] + 1, j < i 且 isPalind[j+1][i] = true }
最终的结果是f[n-1]