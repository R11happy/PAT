/**
* @tag     PAT_B_1038
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 22:11-22:19
* @version 1.0
* @Language C++
* @Ranking  540/1084
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>

int grade[110];

int main(int argc, char const *argv[])
{
    int k,N;
    scanf("%d", &N);
    int cur_grade;
    int query_grade;
    //初始化所有成绩的哈希表
    while(N--)
    {
        scanf("%d" &cur_grade);
        grade[cur_grade]++;
    }
    scanf("%d", &k);
    for(int i = 0; i<k-1; i++)
    {
        scanf("%d", &query_grade);
        printf("%d ", grade[query_grade]);
    }
    scanf("%d", &query_grade);
    printf("%d", grade[query_grade]);
    return 0;
}
