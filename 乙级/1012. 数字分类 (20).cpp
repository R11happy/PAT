/**
* @tag     PAT_B_1008
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-18 21:58:16-22:19
* @version 1.0
* @Language C++
* @Ranking  135/4230
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int a[5];
int count[5];

int main()
{
    int N, num;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (num % 5 == 0 && num % 2 == 0)  //A1类
        {
            a[0] += num;
            count[0]++;
        }
        else if (num % 5 == 1)      //A2类
        {
            if (count[1] % 2 == 0)
                a[1] += num;
            else
                a[1] -= num;
            count[1]++;
        }
        else if (num % 5 == 2) //A3类
        {
            count[2]++;
            a[2] = count[2];
        }
        else if (num % 5 == 3)   //A4类
        {
            a[3] += num;    //a[3]只记录总数，平均数最后再输出
            count[3]++;
        }
        else if (num % 5 == 4)  //A5类
        {
            count[4]++;
            if (num>a[4])
                a[4] = num;
        }
    }
    if (count[0] == 0)
        printf("N ");
    else
        printf("%d ", a[0]);
    if (count[1] == 0)
        printf("N ");
    else
        printf("%d ", a[1]);
    if (count[2] == 0)
        printf("N ");
    else
        printf("%d ", a[2]);
    if (count[3] == 0)
        printf("N ");
    else
        printf("%.1f ", a[3] * 1.0 / count[3]);
    if (count[4] == 0)
        printf("N");
    else
        printf("%d", a[4]);

    return 0;
}
