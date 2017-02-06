/**
* @tag     PAT_B_1041
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-9 22:25:16-23:45
* @version 1.0
* @Language C++
* @Ranking  195/3415
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 1000;

struct Student
{
    long long id;   //学生考号
    int real;   //学生考试座位号
}test[Max];     //以试机座位号作为下标，便于寻找

int main()
{
    int N, T, real, tIndex,index;
    long long id;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%lld %d %d", &id,&tIndex,&real);
        test[tIndex].id = id;
        test[tIndex].real=real;
    }
    //开始处理输入机试编号
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &index);
        printf("%lld %d\n" ,test[index].id, test[index].real );
    }
    return 0;
}






