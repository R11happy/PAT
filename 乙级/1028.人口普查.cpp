/**
* @tag     PAT_B_1028
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 22:22:16-23:08
* @version 1.0
* @Language C++
* @Ranking  235/2964
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Person
{
    char name[7];
    int yy, mm, dd;
};

int main()
{
    Person Max, Min, st;
    int N;
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i<N; i++)
    {
        scanf("%s %d/%d/%d", &st.name, &st.yy, &st.mm, &st.dd);
        //排除年龄过小的
        if (st.yy > 2014 || ((st.yy == 2014) && ((st.mm>9) || ((st.mm == 9) && (st.dd > 6))))) continue;
        //排出年龄过大的
        if (st.yy < 1814 || ((st.yy == 1814) && ((st.mm<9) || ((st.mm == 9) && (st.dd < 6))))) continue;
        //统计年龄合理的人数
        cnt++;
        //如果是第一个，初始化
        if (cnt == 1)   //最开始写成了if(i==0)
        {
            Max = st;
            Min = st;
            continue;
        }
        //找到年龄更小的
        if (st.yy > Min.yy || ((st.yy == Min.yy) && ((st.mm>Min.mm) || ((st.mm == Min.mm) && (st.dd > Min.dd)))))
        {
            Min = st;
        }
        //找到年龄更大的
        if (st.yy < Max.yy || ((st.yy == Max.yy) && ((st.mm<Max.mm) || ((st.mm == Max.mm) && (st.dd < Max.dd)))))
        {
            Max = st;
        }
    }
    //注意处理没有合理年龄的情况
    if (cnt > 0)
    {
        printf("%d %s %s", cnt, Max.name, Min.name);
    }
    else
        printf("%d", cnt);
    return 0;
}
