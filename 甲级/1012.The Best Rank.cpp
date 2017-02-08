/**
* @tag     PAT_A_1012
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-8 14:32-17:00
* @version 1.0
* @Language C++
* @Ranking  805/1670
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    int grade[4];
}stu[2010];

const char course[4] = { 'A', 'C', 'M', 'E' };  //按优先级排序，方便输出
int Rank[10000000][4] = { 0 };    //为学号建立对应排名索引，空间换时间
int cur;    //cmp 函数使用，表示当前按cur号分数排序stu数组
            // stu数组按cur号递减排序
bool cmp(Student a, Student b)
{
    return a.grade[cur] > b.grade[cur];
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    // 处理输入
    for (int i = 0; i<N; i++)
    {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3.0);
    }
    // 对每一类成绩均用sort函数进行排序
    for (cur = 0; cur < 4; cur++)
    {
        sort(stu, stu + N, cmp);
        Rank[stu[0].id][cur] = 1;
        for (int j = 1; j<N; j++)
        {
            if (stu[j].grade[cur] == stu[j - 1].grade[cur])   Rank[stu[j].id][cur] = Rank[stu[j - 1].id][cur];
            else    Rank[stu[j].id][cur] = j + 1;
        }
    }


    int query;  //当前查询的id
    for (int i = 0; i<M; i++)
    {
        scanf("%d", &query);
        if(Rank[query][0] == 0) printf("N/A\n");
        else
        {
            int k = 0;
            for(int j = 1; j<4; j++)
            {
                if(Rank[query][j] < Rank[query][k]) k = j;
            }
            printf("%d %c\n",Rank[query][k], course[k] );
        }
    }
    return 0;
}
