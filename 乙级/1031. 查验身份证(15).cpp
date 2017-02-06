/**
* @tag     PAT_B_1031
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-21 19:03-19:34
* @version 1.0
* @Language C++
* @Ranking  375/1779
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

char reflect[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3' ,'2' };
int weights[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    getchar();  //输入N后有回车，下面如果用gets需要加getchar吸收字符
                //下面用scanf("%s",str)就不用
    int tmp = N;
    int cnt = 0;

    while (N--)
    {
        char str[19];   //最少是19位，多出一位存'\0'
        int sum = 0;
        int flag = 0;
        gets(str);
        for (int i = 0; i<17; i++)
        {
            int digit = str[i] - '0';   //将字符串转化为数字
            if (digit >= 0 && digit <= 9)
            {
                sum += digit*weights[i];    //计算权重和
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag)    puts(str); //puts输出字符串
        else
        {
            if (reflect[sum % 11] != str[17])    puts(str);
            else    cnt++;
        }
    }
    if (cnt == tmp)    printf("All passed\n");
    return 0;
}
