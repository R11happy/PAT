/**
* @tag     PAT_A_1045
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-17 19:05
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
int HashTable[maxc];    //将喜欢的颜色映射为递增序列，不喜欢的映射为-1
int A[maxn], dp[maxn];
int main(int argc, char const *argv[])
{
    int n, m, x;
    scanf("%d%d", &n, &m);
    memset(HashTable, -1, sizeof(HashTable));
    for(int i = 0; i<m; i++)
    {
        scanf("%d", &x);
        HashTable[x] = i;   //递增映射
    }
    int l, num = 0;
    scanf("%d", &l);
    for(int i = 0; i<l; i++)
    {
        scanf("%d", &x);
        if(HashTable[x] != -1)  A[num++] = HashTable[x];    //若是喜欢的颜色，就加入到A数组中
    }
    int ans = -1;
    for(int i = 0; i<num; i++)

        dp[i] = 1;
        for(int j = 0; j<i; j++)
        {
            if(A[i] >= A[j] && dp[j]+1 > dp[i]) dp[i] = dp[j]+1;
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans );
    return 0;
}
