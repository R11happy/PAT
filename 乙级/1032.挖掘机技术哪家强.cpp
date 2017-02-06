/**
* @tag     PAT_B_1032
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 20:51:16-21:28
* @version 1.0
* @Language C++
* @Ranking  255/2741
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Person
{
    int score;
}gur[100005];   //看清所开数组大小，第一次开10005结果测试点3段错误

int main()
{
    int N, score,index, MaxIndex;
    int MaxScore = 0;
    scanf("%d", &N);
    //初始化
    scanf("%d %d", &MaxIndex, &MaxScore);
    gur[MaxIndex].score += MaxScore;    //注意初始化，不能省
    for(int i = 1; i<N; i++)
    {
        scanf("%d %d", &index, &score);
        gur[index].score += score;
        if(gur[index].score >= MaxScore)
        {
            MaxIndex = index;
            MaxScore = gur[index].score;
        }
    }
    printf("%d %d", MaxIndex, MaxScore);
    return 0;
}
