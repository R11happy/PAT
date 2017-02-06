/**
* @tag     PAT_B_1014
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-23 22:09-22：55
* @version 1.0
* @Language C++
* @Ranking  415/1612
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
/*
如果要提前存储，也可以写成
char Clock[] = "0123456789ABCDEFGHIJKLMN";
不过要多一位存储'\0'
 */
/*char Clock[24] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N' };*/
char Week[7][5] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main(int argc, char const *argv[])
{
    char str1[70], str2[70], str3[70], str4[70];
    scanf("%s%s%s%s", str1, str2, str3, str4);
    int cnt = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        /*注意：要在第一个输出之后才接着找第二个相同字符*/
        if (str1[i] == str2[i])
        {
            /*输出星期*/
            if (cnt == 0)
            {
                int index = str1[i] - 'A';
                if (index >= 0 && index <= 6)
                {
                    printf("%s ", Week[index]);
                    cnt++;
                }
            }
            /*输出小时*/
            else /*if (cnt == 1)*/
            {
                /*                for (int j = 0; j<24; j++)
                {
                if (Clock[j] == str1[i])
                {
                printf("%02d:", j);
                cnt++;  //只输出一次，不加会输出多次
                }
                }*/
                if (str1[i] >= '0' && str1[i] <= '9')
                {
                    printf("%02d:", str1[i] - '0');
                    break;
                }
                else if (str1[i] >= 'A' && str1[i] <= 'N')
                {
                    printf("%02d:", str1[i] - 'A' + 10);
                    break;
                }
            }
        }
    }
    /*输出分钟*/
    for (int i = 0; str3[i] != '\0' && str4[i] != '\0'; i++)
    {
        if (str3[i] == str4[i])
        {
            if ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z'))
            {
                printf("%02d", i);
                break;  //输出一个后要马上结束输出
            }
        }
    }
    return 0;
}
