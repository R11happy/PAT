/**
* @tag     null
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  null
* @function 判断某天是星期几
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

//注意要把month[0][2]空出来
int month[13][2] = { { 0,0 },{ 31,31 },{ 28,29 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 } };
//二维数组存储月份名称
char s_month[13][15] = { " ","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
//二维数组存储星期名称，星期数组不用留空
char week[7][15] = { "Monday", "Tuesday", "Wednesday", "Thursday","Friday", "Saturday", "Sunday" };
//判断是否为闰年
bool  isLeap(int year)
{
    return  ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

//通过月份名称获取月份下标
int getMonth(char* str)
{
    int i = 0;
    for (i = 1; i<13; i++)
    {
        if (strcmp(str, s_month[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int time1, y1, m1, d1;
    int time2, y2, m2, d2;
    char str[15];
    while (scanf("%d %s %d", &d2, &str, &y2) != EOF)
    {
        int flag = 0;
        int cnt = 0;
        m2 = getMonth(str);
        time1 = 20160815;   //存储当前时间（星期一）作为标杆
        time2 = y2 * 10000 + m2 * 100 + d2;
        //保证time1时间比较早
        if (time1 > time2)
        {
            flag = 1;
            swap(time1, time2);
        }
        //更新交换后的时间
        y1 = time1 / 10000;
        m1 = time1 % 10000 / 100;
        d1 = time1 % 100;

        y2 = time2 / 10000;
        m2 = time2 % 10000 / 100;
        d2 = time2 % 100;
        //time1不断加1，直到与time2时间相同为止
        while (y1 != y2 || m1 != m2 || d1 != d2)
        {
            d1++;
            //更新下个月时间
            if (d1 == month[m1][isLeap(y1)] + 1)
            {
                m1++;
                d1 = 1;
            }
            //更新下一年时间
            if (m1 == 13)
            {
                y1++;
                m1 = 1;
            }
            cnt++;
        }
        if (!flag)  //输入日期在2016-8-15之后
            printf("%s\n", week[cnt % 7]);
        else    //输入日期在2016-8-15之前
            printf("%s\n", week[6 - (cnt-1) % 7]);
    }

    return 0;
}
