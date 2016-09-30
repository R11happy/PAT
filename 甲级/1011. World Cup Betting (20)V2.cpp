/**
* @tag     PAT_A_1011
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 21:43:16-22:17
* @version 1.0
* @Language C++
* @Ranking  150/4094
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

char S[3] = {'W', 'T', 'L'};

int main()
{
    double ans = 1.0, Max, a;
    int idx;    //记录每行最大元素的下标
    for(int i = 0; i<3; i++)
    {
        Max = 0.0;
        for(int j = 0; j<3; j++)
        {
            scanf("%lf", &a);
            if(a > Max)
            {
                Max = a;
                idx = j;
            }
        }
        ans*=Max;
        printf("%c ", S[idx]);
    }
    printf("%.2f", (ans*0.65-1)*2);
    return 0;
}
