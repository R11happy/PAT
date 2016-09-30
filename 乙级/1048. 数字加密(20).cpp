/**
* @tag     PAT_B_1048
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-27 18:14-
* @version 1.0
* @Language C++
* @Ranking  455/1411
* @function 不反转字符串的做法
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

char mod13[] = "0123456789JQK";

char strA[110], buf_b[220];     //strA起始位置在数组开头
char *strB = buf_b+110;         //strB起始位置在数组中间，位置可以向前移

int main(int argc, char const *argv[])
{

    scanf("%s%s", strA, strB);
    int lenA = strlen(strA);
    int lenB = strlen(strB);
    int currA = lenA - 1;
    int currB = lenB - 1;
    for (; currA >= 0; currA--, currB--)
    {
        //题目真实意思是当lenB < lenA的时候，把strB的少的位数按0来进行数字加密
        if(currB<0) strB[currB] = '0';
        //奇数位，相应位相加后对13取余
        if ((lenB - currB) % 2 == 1)
        {
            int sum = (strA[currA] - '0') + (strB[currB] - '0');
            strB[currB] = mod13[sum % 13];
        }
        //偶数位相减
        else
        {
            int numA = strA[currA] - '0';
            int numB = strB[currB] - '0';
            int sub = numB - numA;
            if (sub < 0) sub += 10;
            strB[currB] = sub + '0';
        }
    }
    if(lenB < lenA) puts(strB+currB+1); //起始位置前移的情况
    else printf("%s\n", strB);  //正常起始位置
    return 0;
}
