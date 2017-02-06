/**
* @tag     PAT_B_1006
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-20 21:22-21:35
* @version 1.0
* @Language C++
* @Ranking  345/2048
* @function 换个格式输出整数
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int cntB = 0, cntS = 0;
    int cntD = 0;
    cntB = n / 100; //存储百位数字
    cntS = n % 100 / 10;    //存储十位数字
    cntD = n % 10;  //存储个位数字
    for(int i = 0; i<cntB; i++) printf("B");
    for(int i = 0; i<cntS; i++) printf("S");
    //因为题目说是正整数，所以也不用考虑n为0的情况
    for(int i = 1; i<=cntD; i++)    printf("%d",i);
    printf("\n");
    return 0;
}
