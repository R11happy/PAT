/**
* @tag     PAT_A_1006
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-13 23:39-24:00
* @version 1.0
* @Language C++
* @Ranking  175/3884
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Sign
{
    char ID[20];
    int inHH;
    int inMM;
    int inSS;
    int outHH;
    int outMM;
    int outSS;
}tmp, First, Last;

//判别是否时间更早
bool EQ(Sign a , Sign b)
{
    if( a.inHH != b.inHH)   return a.inHH <= b.inHH;
    else if( a.inMM != b.inMM)  return a.inMM <= b.inMM;
    else    return a.inSS <= a.inSS;
}

//判别是否时间更晚
bool LQ(Sign a, Sign b)
{
    if(a.outHH != b.outHH)  return a.outHH >= b.outHH;
    else if(a.outMM != b.outMM) return a.outMM >= b.outMM;
    else return a.outSS >= b.outSS;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    First.inHH = 99;    //注意，要先初始化第一个进入的时间
    while(N--)
    {
        scanf("%s %d:%d:%d %d:%d:%d", &tmp.ID, &tmp.inHH, &tmp.inMM, &tmp.inSS, &tmp.outHH, &tmp.outMM, &tmp.outSS);
        if(EQ(tmp, First))
        {
            First = tmp;
        }
        if(LQ(tmp, Last))
        {
            Last = tmp;
        }
    }
    printf("%s %s\n", First.ID, Last.ID );
    return 0;
}
