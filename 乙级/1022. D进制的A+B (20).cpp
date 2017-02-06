/**
* @tag     PAT_B_1022
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-18 18:47-19:01
* @version 1.0
* @Language C++
* @Ranking  310/2280
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int A, B, D;
    int res[31];    //最多31位，用数组来存放最后的结果
    scanf("%d%d%d", &A, &B, &D);
    int sum = A + B;
    int num = 0;    //记录位数
    do  //用do是考虑sum为0的情况
    {
        res[num++] = sum % D;
        sum = sum / D;
    } while (sum != 0);
    //从高位开始输出
    for (int i = num - 1; i >= 0; i--)
    {
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}



