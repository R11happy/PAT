/**
* @tag     PAT_B_1028
* @authors R11happy (xushuai100@126.com)
* @date    2016-08-10 22:22:16-23:08
* @version 2.0
* @Language C++
* @Ranking  235/2964
*/

z
#include <cstdio>
#include <cstdlib>
#include <cstring>

//结构体存储数据
struct Person
{
    char name[7];
    int yy, mm, dd;
}oldest, youngest, left, right, st;

//比较a是否LessOrEqual b
bool LE(Person a, Person b)
{
    if (a.yy != b.yy)    return a.yy <= b.yy;
    else if (a.mm != b.mm)    return a.mm <= b.mm;
    else    return a.dd <= b.dd;
}
//比较a是否MoreOrEqual b
bool ME(Person a, Person b)
{
    if (a.yy != b.yy)    return a.yy >= b.yy;
    else if (a.mm != b.mm)    return a.mm >= b.mm;
    else    return a.dd >= b.dd;
}

//初始化
void init()
{
    youngest.yy = left.yy = 1814;
    oldest.yy = right.yy = 2014;
    youngest.mm = oldest.mm = left.mm = right.mm = 9;
    youngest.dd = oldest.dd = left.dd = right.dd = 6;
}

int  main()
{
    init();
    int N;
    int cnt = 0;  //统计合理的年龄
    scanf("%d", &N);
    while (N--)
    {
        scanf("%s %d/%d/%d", &st.name, &st.yy, &st.mm, &st.dd);
        if (LE(st, right) && ME(st, left))
        {
            cnt++;
            if (LE(st, oldest))   oldest = st;
            if (ME(st, youngest))    youngest = st;
        }
    }
    if (cnt > 0) printf("%d %s %s", cnt, oldest.name, youngest.name);
    else printf("%d", cnt);
    return 0;
}
