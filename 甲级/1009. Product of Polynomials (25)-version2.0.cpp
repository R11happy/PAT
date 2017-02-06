/*
* @tag     PAT_A_1009
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 23:53:15-24:19
* @version 2.0
* @Language C++
* @Ranking  130/4240
*/

#include <cstdio>

struct Poly
{
    int exp;    //指数
    double cof; //系数
}poly[1001];    //第一个多项式

double ans[2001]; //存放结果
int main()
{
    int n, m, cnt = 0;
    scanf("%d", &n);    //第一个多项式中非零系数的项数
    for (int i = 0; i < n; i++)
        scanf("%d%lf", &poly[i].exp, &poly[i].cof);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int exp;
        double cof;
        scanf("%d%lf", &exp, &cof);
        for (int j = 0; j < n; j++)
        {
            ans[exp + poly[j].exp] += cof*poly[j].cof;  //与第一个多项式每一项相乘
        }
    }
    for (int i = 0; i <= 2000; i++) //统计非零项数
    {
        if (ans[i])
            cnt++;
    }
    printf("%d", cnt);
    for (int i = 2000; i >= 0; i--) //遍历整个数组，找非零项输出
    {
        if (ans[i] != 0.0)
        {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}
