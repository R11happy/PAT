/**
* @tag     PAT_B_1047
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-3 12:10-12:26
* @version 1.0
* @Language C++
* @Ranking  620/846
* @function null
*/



#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Grade
{
    int grade = 0;
    int num[11] ={0};   //区分同队不同编号选手，防止同一选手成绩重复记录的情况
}player[1010];

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int num_Group;
    int num_Player;
    int cur_grade;
    int MaxValue = 0, MaxIndex;
    while(N--)
    {
        scanf("%d-%d %d", &num_Group, &num_Player, &cur_grade );
        if(player[num_Group].num[num_Player] == 0)
        {
            player[num_Group].grade += cur_grade;
            player[num_Group].num[num_Player] = 1;
        }
        if(player[num_Group].grade > MaxValue)
        {
            MaxValue = player[num_Group].grade;
            MaxIndex = num_Group;
        }
    }
    printf("%d %d\n", MaxIndex, MaxValue);
    return 0;
}
