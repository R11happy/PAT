/**
* @tag     PAT_A_1083
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-8 18:06-18:40
* @version 1.0
* @Language C++
* @Ranking  855/1584
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student
{
    char name[12];
    char id[12];
    int grade;
}stu[100010];


bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

int main(int argc, char const *argv[])
{
    int N;
    int grade1, grade2;
    int low = -1, high = -1;
    scanf("%d", &N);
    for(int i = 0; i<N; i++)
    {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d %d", &grade1, &grade2);
    sort(stu, stu+N, cmp);
    // // 找到下限
    // for(int i = N-1; i>=0; i--)  //注意是i>=0,一开始写i>0测试点2不过
    // {
    //     if(stu[i].grade >= grade1)
    //     {
    //         low = i;
    //         break;
    //     }
    // }
    // for(int i = 0; i<N; i++)
    // {
    //     if(stu[i].grade <= grade2)
    //     {
    //         high = i;
    //         break;
    //     }
    // }
    // if(low < high) printf("NONE\n");
    // else
    // {
    //     for(int i = high; i<=low; i++)
    //     {
    //         printf("%s %s\n", stu[i].name, stu[i].id);
    //     }
    // }
    int flag = 0;
    for(int i = 0; i<N; i++)
    {
        if(stu[i].grade >= grade1 && stu[i].grade <= grade2)
        {
            printf("%s %s\n",stu[i].name, stu[i].id );
            flag = 1;
        }
    }
    if(!flag)   printf("NONE\n");
    return 0;
}
