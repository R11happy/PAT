/**
* @tag     PAT_A_1025
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-6 22:00 - 22:58
* @version 1.0
* @Language C++
* @Ranking  780/1705
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


struct Student
{
    char id[15];
    int score;
    int location;
    int localRank;  //所在考场的排名
    int globalRank; //总排名
}stu[30010];

bool cmp(Student a, Student b)
{
    if (a.score != b.score)  return a.score > b.score;
    else return strcmp(a.id, b.id) < 0; //一开始写成else return strcmp(a.id, b.id);报错
}

int main(int argc, char const *argv[])
{
    int indexLocation;
    int N, K, index = 0;
    int numOfTestee = 0;
    scanf("%d", &N);
    for (indexLocation = 1; indexLocation <= N; indexLocation++)
    {
        scanf("%d", &K);
        for (int i = 0; i<K; i++)
        {
            scanf("%s %d", stu[numOfTestee].id, &stu[numOfTestee].score);
            stu[numOfTestee].location = indexLocation;
            numOfTestee++;
        }
        // 将该考场排序
        sort(stu + numOfTestee - K, stu + numOfTestee, cmp);
        stu[numOfTestee - K].localRank = 1;
        for (int i = numOfTestee - K + 1; i < numOfTestee; ++i)
        {
            if (stu[i].score == stu[i - 1].score)  stu[i].localRank = stu[i - 1].localRank;
            else    stu[i].localRank = i + K -numOfTestee+1;    //当前所在考场次序下标加1
        }
    }
    // 全体排序
    sort(stu, stu + numOfTestee, cmp);
    stu[0].globalRank = 1;
    for (int i = 1; i<numOfTestee; i++)
    {
        if (stu[i].score == stu[i - 1].score)  stu[i].globalRank = stu[i - 1].globalRank;
        else    stu[i].globalRank = i + 1;
    }
    printf("%d\n", numOfTestee);
    for (int i = 0; i < numOfTestee; ++i)
    {
        printf("%s %d %d %d\n", stu[i].id, stu[i].globalRank, stu[i].location, stu[i].localRank);
    }
    return 0;
}
