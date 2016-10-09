/**
* @tag     PAT_A_1011
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 21:43:16-21:28
* @version 1.0
* @Language C++
* @Ranking  255/2741
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Game
{
  double W;
  double T;
  double L;
  double MaxOdds;
  char Max = 'W';
}res[3];

//3个中找可能性最高的选项
void Max3(Game &res)
{
  res.MaxOdds = res.W;
  if (res.T > res.MaxOdds)
  {
    res.MaxOdds = res.T;
    res.Max = 'T';
  }
  if (res.L > res.MaxOdds)
  {
    res.MaxOdds = res.L;
    res.Max = 'L';
  }
}
int main()
{
  double MaxPro = 0.0;
  for (int i = 0; i < 3; i++)
  {
    scanf("%lf %lf %lf", &res[i].W, &res[i].T, &res[i].L);
    Max3(res[i]);
  }
  MaxPro = (res[0].MaxOdds*res[1].MaxOdds*res[2].MaxOdds*0.65 - 1) * 2;
  printf("%c %c %c %.2f", res[0].Max, res[1].Max, res[2].Max, MaxPro);
  return 0;
}
