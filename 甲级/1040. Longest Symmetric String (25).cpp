/**
* @tag     PAT_A_1040
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-19
* @version 1.0
* @Language C++
* @Ranking  2290/389
* @function null
*/

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
    int len = strlen(S);
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    // 边界
    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = 1;
        if (i < len - 1)
        {
            if (S[i] == S[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    // 转移方程
    for (int L = 3; L <= len; L++)
    {
        for (int i = 0; i + L - 1 < len; i++)
        {
            int j = i + L - 1;
                if (S[i] == S[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    ans = L;
                }
        }
    }
    printf("%d\n", ans);
    return 0;
}
