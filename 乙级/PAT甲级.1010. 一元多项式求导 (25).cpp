/**
* @tag     PAT_B_1010
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-23 17:28:17-17:56
* @version 1.0
* @Language C++
* @Ranking  180/3621
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int poly[1005]; //poly[i]存储输入的多项式指数为i的系数
int ans[1005];  //ans[i]存储结果的多项式指数为i的系数

int main()
{
    int epo, cof;
    int cnt = 0;
    int Max = 1;
    while (scanf("%d%d", &cof, &epo) != EOF)
    {
        poly[epo] = cof;
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (poly[i])
        {
            if (Max < i)
                Max = i;
            ans[i - 1] = i*poly[i];
        }
    }
    printf("%d %d", ans[Max - 1], Max - 1);
    for (int i = Max - 2; i >= 0; i--)
        {
            if (ans[i])
            {
                printf(" %d %d", ans[i], i);
            }
        }
    printf("\n");
    return 0;
}



