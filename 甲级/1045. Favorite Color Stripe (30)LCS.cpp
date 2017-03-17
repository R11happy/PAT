/**
* @tag     PAT_A_1045
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-17 20:12-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int A[maxc], B[maxn], dp[maxc][maxn];
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &A[i]);
    }
    int l;
    scanf("%d", &l);
    for (int i = 1; i <= l; i++)
    {
        scanf("%d", &B[i]);
    }
    // 边界
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 1; j <= l; j++)
    {
        dp[0][j] = 0;
    }
    // 状态转移方程
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            int MAX = max(dp[i - 1][j], dp[i][j - 1]);
            if (A[i] == B[j])
            {
                dp[i][j] = MAX + 1;
            }
            else
            {
                dp[i][j] = MAX;
            }
        }
    }
    printf("%d\n", dp[m][l]);
    return 0;
}
