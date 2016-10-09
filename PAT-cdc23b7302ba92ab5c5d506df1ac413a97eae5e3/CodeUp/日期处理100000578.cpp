/**
* @tag     codeup-100000578
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-15
* @version 1.0
* @Language C++
* @Ranking  null
* @function 计算两个日期的差值
* 思路：日期不断累加，直到与第二个日期相等为止
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;    //直接调用swap函数需要

//统计平年和闰年每个月的天数,month[][0]代表润年，month[][1]代表平年
int month[13][2] = {{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};

bool isLeap(int year)
{
    //判断整除要用%
    return (year % 4==0 && year % 100 != 0) || (year % 400 == 0);
}

int main(int argc, char const *argv[])
{
    int yy1, mm1, dd1;
    int yy2, mm2, dd2;
    long long time1, time2; //也可以用int类型，正负8位都没问题
    //没有指定次数时用
    while(scanf("%lld%lld", &time1, &time2) != EOF)
    {
        int cnt = 1;//有EOF先想初始化
        //第一个日期晚于第二个日期，则交换
        //必须要先交换
        if(time1 > time2)   swap(time1, time2);
        yy1 = time1 / 10000;
        mm1 = time1 % 10000 / 100;
        dd1 = time1 % 100;

        yy2 = time2 / 10000;
        mm2 = time2 % 10000 / 100;
        dd2 = time2 % 100;
        //time1不断递增，直到与time2相等为止
        while(yy1 != yy2 || mm1 != mm2 || dd1 != dd2)
        {
            dd1++;
            //到下一个月
            if(dd1 == month[mm1][isLeap(yy1)] + 1)
            {
                mm1++;
                dd1 = 1;
            }
            //到下一年
            if(mm1 == 13)
            {
                yy1++;
                mm1 = 1;
            }
            cnt++;
        }
        printf("%d\n",cnt );
    }
    return 0;
}
