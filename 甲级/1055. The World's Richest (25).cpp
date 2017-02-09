/**
* @tag    PAT_A_1055
* @authors R11happy (xushuai100@126.com)
* @date   2017-2-9 18:59-19:21
* @version 1.0
* @Language C++
* @Ranking  925/1473
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct Richer
{
    char name[10];
    int age;
    int worth;
}richer[100010];

bool cmp(Richer a, Richer b)
{
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i<N; i++)
    {
        scanf("%s %d %d", richer[i].name, &richer[i].age, &richer[i].worth);
    }
    sort(richer, richer+N, cmp);
    int queryOut, ageMin, ageMax;
    for(int i = 0; i<K; i++)
    {
        int cnt = 0;
        scanf("%d%d%d", &queryOut, &ageMin, &ageMax);
        printf("Case #%d:\n",i+1);
        for(int index = 0; index<N; index++)
        {
            if(cnt >= queryOut) break;
            else if(richer[index].age >= ageMin && richer[index].age <= ageMax)
            {
                printf("%s %d %d\n",richer[index].name,richer[index].age, richer[index].worth );
                cnt++;
            }
        }
        if(cnt == 0)    printf("None\n");
    }

    return 0;
}
