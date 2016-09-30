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
/*
//得到底边的符号数
int getCol(int n)
{
  int upper = 0;
  int sum = 0;
  int i;
  for (i = 0; i<n; i++)
  {
    upper += (i * 2 + 1);
    sum = 2 * upper - 1;
    if (sum > n) return 2 * i - 1;
    if (sum == n)   return 2*i + 1; //考虑测试点2：n=1的情况
  }
  return -1;
}*/

//得到底边的符号数
int getCol(int n)
{
  int upper = 0;
  int sum = 0;
  int i = 1;
  for (i; i<=n; i++)
  {
    upper += (i * 2 - 1);
    sum = 2 * upper - 1;
    if (sum > n) break;
  }
  return 2*i-3;
}   //测试点2为n=1的情况

int main(int argc, char const *argv[])
{
  int i, N;
  char ch;
  int col;
  int cnt = 0;
  scanf("%d %c", &N, &ch);
  col = getCol(N);
  if (N)
  {
    //打印上半部分(包括中间的)
    for (i = col; i >= 1; i -= 2)
    {
      for (int k = 0; k<(col - i) / 2; k++)
      {
        printf(" ");
      }
      for (int j = 0; j<i; j++)
      {
        printf("%c", ch);
        cnt++;
      }
      printf("\n");
    }
    //打印下半部分
    for (i += 4; i <= col; i += 2)
    {
      for (int k = 0; k<(col - i) / 2; k++)
      {
        printf(" ");
      }
      for (int j = 0; j<i; j++)
      {
        printf("%c", ch);
        cnt++;
      }
      printf("\n");
    }
  }
  //打印剩余符号
  printf("%d\n", N - cnt);
  return 0;
}
