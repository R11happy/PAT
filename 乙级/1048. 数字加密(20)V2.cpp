/**
* @tag     PAT_B_1048
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-27 18:14-
* @version 2.0
* @Language C++
* @Ranking  455/1411
* @function 反转字符串的做法
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

char mod13[] = "0123456789JQK";

const int Max = 110;
char strA[Max], strB[Max], ans[Max];

void reverse(char s[])
{
    int len = strlen(s);
    for(int i = 0; i < len/2; i++)  //注意：不能写成i <= len/2
    {
        int tmp = s[i];
        s[i] = s[len -1 - i];
        s[len -1 - i] = tmp;
    }
}

int main(int argc, char const *argv[])
{

    scanf("%s%s", strA, strB);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    reverse(strA);  //将strA和strB反转
    reverse(strB);
    int len = lenA > lenB? lenA: lenB;  //取长的
    for(int i = 0; i<len; i++)
    {
        int numA = i<lenA? strA[i] - '0': 0;    //strA[i]位置字符对应的数字
        int numB = i<lenB? strB[i] - '0': 0;    //strB[i]位置字符对应的数字
        if(i%2 == 0 )   //对应加密算法的奇数位
        {
            int sum = numA + numB;
            ans[i] = mod13[sum%13];
        }
        else    //对应加密算法的偶数位
        {
            int sub = numB - numA;
            if(sub < 0 )    sub += 10;
            ans[i] = sub + '0';
        }
    }
    reverse(ans);   //反转输出
    puts(ans);
    return 0;
}
