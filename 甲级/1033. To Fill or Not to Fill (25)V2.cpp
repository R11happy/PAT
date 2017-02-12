/**
* @tag     PAT_A_1033
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-11 16:34-19:14
* @version 2.0
* @Language C++
* @Ranking  1060/1281
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct station
{
    double price, dis;
}st[maxn];

bool cmp(station a, station b)
{
    return a.dis < b.dis;
}

int main(int argc, char const *argv[])
{
    int n;
    double cMax, D, dAvg;
    scanf("%lf%lf%lf%d", &cMax, &D, &dAvg, &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    // 设置终点为油单价0，距离起点D的加油站
    st[n].price = 0;
    st[n].dis = D;
    // 所有加油站按距离从小到大排序
    sort(st, st+n, cmp);
    if(st[0].dis != 0)
    {
        printf("The maximum travel distance = 0.00\n");
    }
    else
    {
        int now = 0;    //当前所处的加油站编号
        // 总花费、当前油量及满油行驶距离
        double ans = 0, nowTank = 0, Max = cMax*dAvg;
        while(now < n)  //每次循环将选出下一个需要到达的加油站
        {
            // 选出从当前加油站加满油能到达范围内的第一个油价低于当前油价的加油站
            // 如果没有低于当前油价的加油站，则选择价格最低的那个
            int k = -1; //最低油价的加油站编号
            double priceMin = INF;  //最低油价
            for(int i = now+1; i<=n&&st[i].dis - st[now].dis <= Max; i++)
            {
                if(st[i].price < priceMin)
                {
                    priceMin = st[i].price;
                    k = i;
                    // 如果找到第一个油价低于当前油价的加油站，直接中断循环
                    if(priceMin < st[now].price)    break;
                }
            }


            if(k == -1) break;  //满油状态下无法找到加油站，退出循环输出结果
            // need为从now到k需要的油量
            double need = (st[k].dis - st[now].dis)/dAvg;
            // 如果加油站k的油价低于当前油价
            if(priceMin < st[now].price)
            {
                // 只买足够到达加油站k的油
                if(nowTank < need)
                {
                    ans += (need - nowTank)*st[now].price;
                    nowTank = 0;
                }
                else
                {
                    nowTank -= need;
                }
            }
            else    //如果加油站k的油价高于当前油价
            {
                ans += (cMax - nowTank)*st[now].price;  //将邮箱加满
                nowTank = cMax - need;
            }
            now = k;    //到达加油站k，进入下一层循环
        }
        if(now == n) //能到达终点
        {
            printf("%.2f\n", ans );
        }
        else
        {
            printf("The maximum travel distance = %.2f\n", st[now].dis + Max);
        }
    }
    return 0;
}
