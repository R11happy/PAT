/**
* @tag     PAT_B_1004
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 21:11:16-21:25
* @version 1.0
* @Language C++
* @Ranking  215/3171
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Student
{
    char name[15];
    char sID[15];
    int score;
};

int main()
{
    Student Max, Min, st;
    Max.score=0;
    Min.score=100;
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%s%s%d", &st.name, &st.sID; &st.score);
        if(st.score >= Max.score) Max = st;
        if(st.score <= Min.score) Min = st;
    }
    printf("%s %s\n" ,Max.name, Max.sID);
    printf("%s %s\n" ,Min.name, Min.sID);

    return 0;
}
