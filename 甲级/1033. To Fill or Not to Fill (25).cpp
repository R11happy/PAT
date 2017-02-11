/**
* @tag     PAT_A_1033
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-11 16:34-19:14
* @version 1.0
* @Language C++
* @Ranking  1060/1281
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Station
{
    double price;
    double dis;
}station[550];

bool cmp(Station a, Station b)
{
    if (a.dis != b.dis) return a.dis < b.dis;
    else return a.price < b.price;
}

int cur;    //当前到达的加油站号

int main(int argc, char const *argv[])
{
    double cMax, D, dAvg, curTank = 0;
    int j, N;
    double totalPrice = 0;
    scanf("%lf%lf%lf%d", &cMax, &D, &dAvg, &N);
    for (int i = 0; i<N; i++)
    {
        scanf("%lf%lf", &station[i].price, &station[i].dis);
    }
    sort(station, station + N, cmp);
    station[N].price = 0;
    station[N].dis = D;
    if (station[0].dis > 0)  printf("The maximum travel distance = 0.00\n");
    else {
        while (cur<N)
        {

            int minIndex = cur + 1;
            int flag = 0;   //结束的标志
            for (j = cur + 1; j <= N; j++)
            {
                // 首先，要满足在当前加油站加满油可以到
                if (station[cur].dis + (cMax * dAvg) >= station[j].dis)
                {
                    flag = 1;
                    // 能找到比当前加油站油价低的
                    if (station[j].price < station[cur].price)
                    {
                        flag = 2;
                        if ((station[j].dis - station[cur].dis) / dAvg >= curTank)
                        {
                            totalPrice = totalPrice + station[cur].price*((station[j].dis - station[cur].dis) / dAvg - curTank);
                            curTank = 0;
                        }
                        else    curTank = curTank - ((station[j].dis - station[cur].dis) / dAvg);
                        cur = j;
                        break;
                    }
                    else
                    {
                        if (station[j].price < station[minIndex].price)
                        {
                            minIndex = j;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            if (flag == 1)    //找不到加满油范围内比当前加油站油价低的，选择去油价最低的加油站，并在当前加油站加满油
            {
                totalPrice = totalPrice + station[cur].price*(cMax - curTank);
                curTank = cMax - (station[minIndex].dis - station[cur].dis) / dAvg;
                cur = minIndex;
            }
            else if (flag == 0)
            {
                printf("The maximum travel distance = %.2f\n", station[cur].dis + cMax*dAvg);
                break;
            }

        }
        if (cur == N)    printf("%.2f\n", totalPrice);
    }
    return 0;
}
