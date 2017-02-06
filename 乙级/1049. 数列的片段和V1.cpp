/**
* @tag     PAT_B_1049
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 23:47-
* @version 1.0
* @Language C++
* @Ranking  没有AC 17/20
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    double ans = 0.0;
    double tmp = 0.0;
    double last = 0.0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lf", &tmp);
        last += i*tmp;    //浮点精度的问题，运算太多次导致误差积累到了个位数……
        ans += last;
    }
    printf("%.2f\n", ans);
    return 0;
}
