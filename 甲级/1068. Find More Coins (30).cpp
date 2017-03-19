/**
* @tag     PAT_A_1068
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-19 16:14-16:59
* @version 1.0
* @Language C++
* @Ranking  2320/376
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 10010;
const int maxv = 110;
int dp[maxn], w[maxn];
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b)
{
    return a > b;
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int v = m; v >= w[i]; v--)
        {
            if (dp[v] <= dp[v - w[i]] + w[i])
            {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = 1;   //放入第i个物品
            }
            else choice[i][v] = 0;
        }
    }
    if (dp[m] != m)  printf("No Solution\n");    //无解
    else {
        // 记录最优路径
        int k = n, num = 0, v = m;
        while (k >= 0)
        {
            if (choice[k][v] == 1)
            {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else flag[k] = false;
            k--;
        }
        for (int i = n; i>0; i--)
        {
            if (flag[i] == true)
            {
                printf("%d", w[i]);
                num--;
                if (num > 0) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
