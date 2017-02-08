/**
* @tag     PAT_A_1028
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-8 17:44-18:02
* @version 1.0
* @Language C++
* @Ranking  830/1617
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
    char name[9];
    int grade;
}stu[100010];

bool cmp1(Student a, Student b)
{
    return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
    if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else return a.id < b.id;
}

bool cmp3(Student a, Student b)
{
    if (a.grade != b.grade)  return a.grade < b.grade;
    else return a.id < b.id;
}

int main(int argc, char const *argv[])
{
    int N, C;
    scanf("%d%d", &N, &C);
    for (int i = 0; i<N; i++)
    {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
    }
    if (C == 1)  sort(stu, stu + N, cmp1);
    else if (C == 2) sort(stu, stu + N, cmp2);
    else sort(stu, stu + N, cmp3);
    for (int i = 0; i<N; i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    return 0;
}
