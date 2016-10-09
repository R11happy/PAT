/**
* @tag     PAT_B_1027
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-14 5:26-6:10
* @version 1.0
* @Language C++
* @Ranking  290/2389
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int main(int argc, char const *argv[])
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    int bottom = floor(sqrt(2*(n+1))) - 1;  //得到底边的字符数
    if(bottom % 2 == 0) bottom--;   //偶数修正，得到奇数
    int used = (bottom+1)*(bottom+1)/2 - 1; //总输出的非空格字符数
    //打印上半部分(包括中间的)
    for (int i = bottom; i >= 1; i -= 2)
    {
      for (int k = 0; k<(bottom - i) / 2; k++)
      {
        printf(" ");
      }
      for (int j = 0; j<i; j++)
      {
        printf("%c", ch);
      }
      printf("\n");
    }
    //打印下半部分
    for (int i = 3; i <= bottom; i += 2)
    {
      for (int k = 0; k<(bottom - i) / 2; k++)
      {
        printf(" ");
      }
      for (int j = 0; j<i; j++)
      {
        printf("%c", ch);
      }
      printf("\n");
    }
    printf("%d\n", n - used );
    return 0;
}

