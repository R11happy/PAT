/**
* @tag     PAT_A_1045
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-13 10:14-10:53
* @version 1.0
* @Language C++
* @Ranking 620/1767
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxc = 210;
const int maxn = 10010;
int HashTable[maxc];
int a[maxn], dp[maxn];  //a数组用来存放所有有用的元素

int main(int argc, char const *argv[])
{
    int N, M, L, tmp;
    int num = 0;
    int ans = -1;   //记录最大dp
    scanf("%d %d", &N, &M);
    memset(HashTable, -1, sizeof(HashTable));   //初始化全部映射为-1
    for (int i = 0; i<M; i++)
    {
        scanf("%d", &tmp); //记录
        HashTable[tmp] = i;
    }

    scanf("%d", &L);
    for (int i = 0; i<L; i++)
    {
        scanf("%d", &tmp);
        if (HashTable[tmp] >= 0)  a[++num] = HashTable[tmp]; //如果tmp是喜欢的元素，就加入进来
        // 注意把HashTable[tmp]添加进来
        // 注意条件是HashTable[tmp] >= 0 而不是>0
    }

    for (int i = 1; i <= num; i++)
    {
        dp[i] = 1;  //注意初始化为1
        for (int j = 1; j<i; j++)
        {
            if (a[j] <= a[i] && dp[j] + 1 > dp[i])   dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);  //更新LIS长度
    }
    printf("%d\n", ans);
    return 0;
}
