/**
 * @tag     PAT_B_1026
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-18 19:28:16-19:43
 * @version 1.0
 * @Language C++
 * @Ranking  80/5481
 */

#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int C1, C2;
    int hh, mm, ss;
    scanf("%d%d", &C1, &C2);
    double ans = (C2 - C1) / 100.0; //注意要用100.0获得double类型
    int Dif = (C2 - C1) / 100;
    /*进行四舍五入*/
    if (ans - Dif >= 0.5)
        Dif++;
    ss = Dif % 60;
    mm = (Dif) / 60 % 60;
    hh = Dif / 3600;
    printf("%02d:%02d:%02d\n", hh, mm, ss); //输出注意两位补0
    return 0;
}
