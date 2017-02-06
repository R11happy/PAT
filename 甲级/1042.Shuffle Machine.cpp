/**
* @tag     PAT_A_1042
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 21:40:16-23:00
* @version 1.0
* @Language C++
* @Ranking  20/7836
*/

#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 54;
char mp[5] = { 'S', 'H', 'C', 'D', 'J' };
int begin[55] = { 0 }, order[55] = { 0 }, end[55] = { 0 };

int main()
{
    int K, flag;
    int n;
    scanf("%d", &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        order[i] = n - 1;       //保存顺序
        end[i] = i;    //无shuffle就原顺序
    }
    // end[0] = 2, end[1] = 17, end[2] = 26, end[3] = 51, end[4] = 53;
    while (K--)
    {
        for (int j = 0; j<N; j++)
        {
            begin[j] = end[j];
        }
        for (int i = 0; i < N; i++)
        {
            end[order[i]] = begin[i];
            // printf("end[%d]= %d\n", order[i], begin[i]);
        }
    }
    for (int i = 0; i<N; i++)
    {
        flag = end[i] / 13;
        if (i < N - 1)
        {
            printf("%c%d", mp[flag], end[i] % 13 + 1);
            printf(" ");
        }
        else
            printf("%c%d", mp[flag], end[i] % 13 + 1);
    }
    return 0;
}
