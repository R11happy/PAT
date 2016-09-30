/**
* @tag     PAT_B_1015
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-1 16:54-17:32
* @version 1.0
* @Language C++
* @Ranking  480/1259
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 100000;

struct Student
{
    int id; //由于题目说是8位，int恰好够用
    int moral;
    int ability;
    int rank;   //1~4   用来分类
}stu[Max + 10], tmp;

bool cmp(Student a, Student b)
{
    if(a.rank != b.rank)    return a.rank < b.rank; //各组升序
    int sumA = a.moral+a.ability;
    int sumB = b.moral+b.ability;
    if(sumA != sumB)    return sumA > sumB; //总分降序
    else if(a.moral != b.moral) return a.moral > b.moral;   //徳分降序
    else    return a.id < b.id; //id升序
}

int main(int argc, char const *argv[])
{
    int N, M = 0;
    int L_grade, H_grade;
    scanf("%d%d%d", &N, &L_grade, &H_grade);
    while (N--)
    {
        scanf("%d %d %d", &tmp.id, &tmp.moral, &tmp.ability);
        if (tmp.moral >= L_grade && tmp.ability >= L_grade)
        {
            if(tmp.moral >= H_grade && tmp.ability >= H_grade)
            {
                tmp.rank = 1;   //才德全尽
            }
            else if(tmp.moral >= H_grade && tmp.ability < H_grade)
            {
                tmp.rank = 2;   //徳胜才
            }
            else if(tmp.moral < H_grade && tmp.ability < H_grade && tmp.moral >= tmp.ability)
            {
                tmp.rank = 3;   //才德兼亡
            }
            else    tmp.rank = 4;
            stu[M++] = tmp;
        }
    }
    sort(stu, stu+M, cmp);  //按cmp规则排序
    printf("%d\n", M );
    for(int i = 0; i<M; i++)
    {
        printf("%d %d %d\n",stu[i].id, stu[i].moral, stu[i].ability );
    }
    return 0;
}
