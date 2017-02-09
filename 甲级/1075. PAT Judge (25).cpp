/**
* @tag     PAT_A_1075
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-9 19:47-
* @version 1.0
* @Language C++
* @Ranking  1443/950
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int score;
    int solved;
    int rank;
}stu[20010];

int problem[5];
int grade[20010][6];

bool cmp(Student a, Student b)
{
    if (a.score != b.score)  return a.score > b.score;
    else if (a.solved != b.solved) return a.solved > b.solved;
    else return a.id < b.id;
}

int main(int argc, char const *argv[])
{
    memset(grade, -1, sizeof(grade));
    int N, K, M;
    int index = 0;
    scanf("%d%d%d", &N, &K, &M);
    for (int i = 0; i<K; i++)
    {
        scanf("%d", &problem[i]);
    }
    int userId, problemId, partialScoreObtained;
    for (int i = 0; i<M; i++)
    {
        scanf("%d%d%d", &userId, &problemId, &partialScoreObtained);
        // 当总成绩会发生改变时
        if (partialScoreObtained > grade[userId][problemId - 1])
        {
            // 如果此id之前没有出现过
            if (grade[userId][5] < 0)
            {
                // 最后一位，记录对应的index
                grade[userId][5] = index;
                stu[index++].id = userId;
            }
            // 更新此id的总成绩
            if(grade[userId][problemId-1] < 0) stu[grade[userId][5]].score = stu[grade[userId][5]].score  + partialScoreObtained;
            else stu[grade[userId][5]].score = stu[grade[userId][5]].score - grade[userId][problemId - 1] + partialScoreObtained;
            // 更新此id的成绩表
            grade[userId][problemId - 1] = partialScoreObtained;
            // 更新AC的题目数
            if (partialScoreObtained == problem[problemId - 1])  stu[grade[userId][5]].solved++;
        }
        else if(grade[userId][problemId-1] < 0) grade[userId][problemId-1] = 0;
    }
    sort(stu, stu + index, cmp);    //开始写成sort(stu, stu+N, cmp)，最后一个测试点不过
    stu[0].rank = 1;
    for (int i = 1; i<N; i++)
    {
        if (stu[i].score == stu[i - 1].score)  stu[i].rank = stu[i - 1].rank;
        else    stu[i].rank = i + 1;
    }
    for (int i = 0; i<index; i++)
    {
        printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].score);
        for (int j = 0; j<K; j++)
        {
            if (grade[stu[i].id][j] == -1)   printf(" -");
            else printf(" %d", grade[stu[i].id][j]);
        }
        printf("\n");
    }
    return 0;
}



