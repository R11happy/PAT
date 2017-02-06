/**
* @tag     PAT_A_1019
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-19 23:05-23:17
* @version 1.0
* @Language C++
* @Ranking  240/3312
* @function 计算整数n在b进制下是否是回文数字
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int ans[32]={0};
    int N, b;
    int num = 0;    //记录位数
    int flag = 1;   //标记是否为回文
    scanf("%d%d", &N, &b);
    //除基转余 来转换进制
    do
    {
        ans[num++] = N % b;
        N = N / b;
    } while (N != 0);
    //判断是否是回文
    for (int i = 0; i <= num/2; ++i)
    {
        if(ans[i] != ans[num-1-i])
        {
            flag = 0;
            break;
        }
    }
    if(flag)    printf("Yes\n");
    else    printf("No\n");
    for(int i = num-1; i > 0; i--)
    {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[0]);
    return 0;
}
