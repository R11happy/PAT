/**
* @tag     PAT_B_1021
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-20 21:45-21:57
* @version 1.0
* @Language C++
* @Ranking  360/1936
* @function 个位数统计
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int D[10] = {0};
    int num = 0;
    char N[1000];
    gets(N);    //读取字符串
    int len = strlen(N);
    for(int i = 0; i<len; i++)
    {
        num = N[i] - '0';   //将字符串转化为整数
        D[num]++;   //对应计数器自增
    }
    for(int i = 0; i<10; i++)
    {
        if(D[i])    printf("%d:%d\n", i, D[i]); //注意，输出的是D[i]而不是N[i]
    }
    return 0;
}
