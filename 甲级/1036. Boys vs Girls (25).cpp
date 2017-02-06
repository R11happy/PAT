/**
* @tag     PAT_A_1036
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-14 0:32-0:50
* @version 1.0
* @Language C++
* @Ranking  200/3685
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Info
{
    char name[15];
    char gender;
    char ID[15];
    int grade;

}FMax, MMin, tmp;

int main(int argc, char const *argv[])
{
    //初始化
    FMax.grade = -1;
    MMin.grade = 101;
    bool flag = true;
    int N;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s %c %s %d", &tmp.name, &tmp.gender, &tmp.ID, &tmp.grade);
        if(tmp.gender == 'F')
        {
            if(tmp.grade >= FMax.grade)
                FMax = tmp;
        }
        else
        {
            if(tmp.grade <= MMin.grade)
                MMin = tmp;
        }
    }
    //输出最高分的Female
    if(FMax.gender != 'F')
    {
        printf("Absent\n");
        flag = false;
    }
    else
    {
        printf("%s %s\n", FMax.name, FMax.ID);
    }

    //输出最低分的Male
    if (MMin.gender != 'M')
    {
        printf("Absent\n");
        flag = false;
    }
    else
    {
        printf("%s %s\n", MMin.name, MMin.ID);
    }
    if (flag)
    {
        printf("%d\n", FMax.grade-MMin.grade);
    }
    else
        printf("NA\n");
    return 0;
}
