/**
* @tag     PAT_B_1041
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-9 22:25:16-23:45
* @version 1.0
* @Language C++
* @Ranking  195/3415
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

long long Sid[1005];    //存储学号
int sim[1005];      //存储试机座号
int real[1005];     //存储考试座号

int main()
{
    int N, T;
    int num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld%d%d", &Sid[i], &sim[i], &real[i]);
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &num);
        //暴力遍历寻找匹配的学生
        for (int i = 0; i<N; i++)
        {
            if (sim[i] == num)
            {
                printf("%lld %d\n", Sid[i], real[i]);
            }
        }
    }
    return 0;
}
