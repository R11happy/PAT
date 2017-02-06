/**
* @tag     PAT_B_1020
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-4 18:55-19:15
* @version 1.0
* @Language C++
* @Ranking  670/756
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Moon
{
    double store;
    double sale;
    double per_sale;
}moon[1010];

bool cmp(Moon a, Moon b)
{
    return a.per_sale > b.per_sale;
}

int main(int argc, char const *argv[])
{
    double  profit = 0.0;
    int N, D;
    int Max_per_sale = 0;
    scanf("%d %d", &N, &D);
    for(int i = 0; i<N; i++)
    {
        scanf("%lf", &moon[i].store);
    }
    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &moon[i].sale);
        moon[i].per_sale = moon[i].sale / moon[i].store;
    }
    //按单个利润，从高到低排序
    sort(moon, moon+N, cmp);
    //从利润高的开始，将profit加进来
    for(int i = 0; i<N; i++)
    {
        if(D > moon[i].store)
        {
            D -= moon[i].store;
            profit += moon[i].sale;
        }
        else
        {
            profit += moon[i].per_sale * D;
            break;
        }
    }
    printf("%.2f\n" ,profit);
    return 0;
}
