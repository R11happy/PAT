/**
* @tag     背包相关
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-19
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

/**
 * 01背包问题：有n件物品，每件物品的重量为w[i],价值为c[i]。现有一个容量为V的背包，问如何选取物品放入背包，使得背包内物品的总价值最大。
 * 其中每种物品只有一件
 */
// dp[i][v]表示前i件物品（1<=i<=n, 0<=v<=V)恰好装入容量为v的背包中所能获得的最大价值
// 不放第i件物品 dp[i][v] = dp[i-1][v]
// 放第i件物品dp[i][v] = dp[i-1][v-w[i]]+c[i]
for (int i = 1; i <= n ; ++i)
{
    for(int v = w[i]; v<=V; v++)
    {
        dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i]]+c[i]);
    }
}

// 滚动数组形式
for(int i = 1; i<=n; i++)
{
    for(int v = V; v>=w[i]; v--)    //逆序枚举v
    {
        dp[v] = max(dp[v], dp[v-w[i]]+c[i]);
    }
}

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;   //物品最大件数
const int maxv = 1000;  //V的上限

int w[maxn], c[maxn], dp[maxv];
int main(int argc, char const *argv[])
{
    int n, V;
    scanf("%d%d", &n, &V);
    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &c[i]);
    }
    // 边界
    for (int v = 0; v <= V; v++)
    {
        dp[v] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int v = V; v >= w[i]; v--)
        {
            // 状态转移方程
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    // 寻找dp[0……V]总最大的即为答案
    int max = 0;
    for (int v = 0; v <= V; v++)
    {
        if (dp[v] > max) max = dp[v];
    }
    printf("%d\n", max);
    return 0;
}

