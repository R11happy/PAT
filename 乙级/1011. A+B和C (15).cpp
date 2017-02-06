/**
 * @tag     PAT_B_1011
 * @authors R11happy (xushuai100@126.com)
 * @date    2016-07-18 16:58:16-17:12
 * @version 1.0
 * @Language C++
 * @Ranking  50/6950
 */
#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int T;
    long long a, b, c;
    int ccase=1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a+b > c)
        {
            printf("Case #%d: true\n", ccase);
        }
        else
            printf("Case #%d: false\n", ccase);
        ccase++;
    }
    return 0;
}
