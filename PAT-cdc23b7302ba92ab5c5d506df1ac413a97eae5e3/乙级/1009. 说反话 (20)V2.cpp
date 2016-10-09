/**
* @tag     PAT_B_1009
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-21 20:39-21:01
* @version 2.0
* @Language C++
* @Ranking  395/1690
* @function null
*
/*针对单点测试，使用EOF来判断单词是否已经输入完毕
在黑框中手动输入时，系统并不知道什么时候到达了所谓的“文件末尾”，因此需要按<ctrl + Z>组合键再按<Enter>键的方式来告诉系统已经到了EOF，这样系统才会结束while*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int num = 0;    //单词的个数
    char ans[90][90];
    // 当scanf返回值不为-1时反复读取单词
    while(scanf("%s", ans[num])!=EOF)
    {
        num++;
    }
    for(int i = num -1; i >= 0; i--)    //倒着输出单词
    {
        printf("%s", ans[i] );
        if(i > 0)   printf(" ");
    }
    return 0;
}
