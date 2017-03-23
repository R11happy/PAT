/*
* @tag     DP问题
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-17 14：03-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

/**
 * 最大连续子序列和
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int A[maxn], dp[maxn];  //A[i]存放序列，dp[i]存放以A[i]结尾的连续序列的最大和
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }
    // 边界
    dp[0] = A[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i] = max(A[i], dp[i-1]+A[i]);
    }
    // dp[i]存放以A[i]结尾的连续序列的最大和，需要遍历i得到最大的才是结果
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if(dp[i] > dp[k])
        {
            k = i;
        }
    }
    printf("%d\n",dp[k]);
    return 0;
}

/**
* @tag     最长不下降子序列(LIS) 有nlogn的算法？
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-13 12:49-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;
int A[N], dp[N];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }
    int ans = -1;   //记录最大的dp[i]
    // 按顺序计算出dp[i]的值
    for(int i = 1; i<=n; i++)
    {
        dp[i] = 1;  //边界初始条件(即先假设每个元素自成一个子序列)
        for(int j = 1; j<i; j++)
        {
            if(A[j] <= A[i] && (dp[j]+1 > dp[i]))
            {
                dp[i] = dp[j] + 1;  //状态转移方程，用以更新dp[i]
            }
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n",ans );
    return 0;
}

/**
* @tag     最大公共子序列(LCS)
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/
// dp[i][j]表示字符串A的i号位和字符串B的j号位之前的LCS长度
// 状态转移方程：
// dp[i][j] :if(A[i] == B[j])   dp[i-1][j-1]+1;
//           else(A[i] != B[j]) max(dp[i-1][j], dp[i][j-1])
// dp[i][0] = dp[0][j] = 0;
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;
char A[N], B[N];
int dp[N][N];
int main(int argc, char const *argv[])
{
    int n;
    gets(A+1);  //从下标为1开始读入
    gets(B+1);
    int lenA = strlen(A+1); //由于读入时下标从1开始，因此读取长度也从+1开始
    int lenB = strlen(B+1);
    // 边界
    for(int i = 0; i<=lenA; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j<=lenB; j++)
    {
        dp[0][j] = 0;
    }
    // 状态转移方程
    for(int i = 1; i<=lenA; i++)
    {
        for(int j = 1; j<=lenB; j++)
        {
            if(A[i] == B[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // dp[lenA][lenB]是答案
    printf("%d\n",dp[lenA][lenB] );
    return 0;
}

/**
* @tag     最长回文子串
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-18 22:44-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

// dp[i][j]表示S[i]到S[j]的子串是否是回文子串   是为1，不是为0
//dp[i][j]: if S[i] == S[j] dp[i+1][j-1]
//          else if S[i] != S[j] 0
//边界：dp[i][i]=1   dp[i][i+1] = (S[i] == S[i+1])?1:0

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
    gets(S);
    int len = strlen(S), ans 1;
    memeset(dp, 0, sizeof(dp));
    // 边界
    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = 1;
        if(i < len-1)
        {
            if(S[i] == S[i+1])
            {
                dp[i][i+1] = 1;
                ans = 2;    //初始化时注意当前最长回文子串长度
            }
        }
    }
    // 状态转移方程
    for(int L = 3; L<=len; L++) //枚举子串长度
    {
        for(int i = 0; i+L-1<len; i++)  //枚举子串的起始端点
        {
            int j = i+L-1;  //子串的右端点
            {
                if(S[i] == S[j] && dp[i+1][j-1] == 1)
                {
                    dp[i][j] = 1;
                    ans = L;    //更新最长回文子串长度
                }
            }
        }
    }
    printf("%d\n",ans );
    return 0;
}

/**
* @tag     DAG(有向无环图)最长路
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  null
* @function 给定有向无环图，求解整个图的所有路径中权值之和最大的那条
*/
// dp[i]表示从i号顶点出发能获得的最长路径长度
int DP(int i)
{
    if(dp[i] > 0)   return dp[i];
    for(int j = 0; j<n; j++)
    {
        if(G[i][j] != INF)  dp[i] = max(dp[i], DP[j]+G[i][j]);
    }
    return dp[i];
}

// 记录路径版
// choice数组存放后继结点
int DP(int i)
{
    if(dp[i] > 0)   return dp[i];
    for(int j = 0; j<n; j++)    //遍历i所有出边
    {
        if(G[i][j] != INF)
        {
            int tmp = DP[j] + G[i][j];  //单独计算，防止if中调用DP函数两次
            if(tmp > dp[i])
            {
                dp[i] = tmp;
                choice[i] = j;  //i号顶点的后继顶点为j
            }
        }
    }
    return dp[i];
}

// 调用printPath前需要先得到最大的dp[i]，然后将i作为路径起点传入
// 且已自动实现长度相同时，按路径序列字典序排序
void printPath(int i)
{
    printf("%d", i);
    while(choice[i] != -1)  //choice数组要先初始化为-1
    {
        i = choice[i];
        printf("->%d",i );
    }
    printf("\n");
}

/**
 * 固定终点，求DAG的最长路径
 * 初始化dp数组为一个负大数，保证“无法到达终点”
 * 设置一个vis数组表示顶点是否已经被计算
 */
int DP(int i)
{
    if(vis[i])  return dp[i];
    vis[i] = true;
    for(int j = 0; j<n; j++)
    {
        if(G[i][j] != INF)
        {
            dp[i] = max(dp[i], DP[j]+G[i][j]);
        }
    }
    return dp[i];
}


