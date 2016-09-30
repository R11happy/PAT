/**
* @tag     PAT_B_1024
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-23 23:52-0:52
* @version 1.0
* @Language C++
* @Ranking  435/1515
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int i, len_base=1;
    int index = 0;
    int exp = 0;
    int flag = 0;   //记录指数正负
    char str[10010];    //一个char 1 byte,9999byte 至少开10000
    char base[10010];
    gets(str);
    if(str[0] == '-')   printf("-");
    base[0] = str[1];   //获得小数点前的数字
    for( i =3; str[i] != 'E'; i++, len_base++)
    {
        base[len_base] = str[i];   //注意：len_base最后比实际多1
    }
    //获得指数数字
    i++;
    if(str[i] == '-')   flag = 1;
    for(i++; str[i] != '\0'; i++)
    {
        exp = exp*10;
        exp += str[i] - '0';
    }
    //如果exp不为0， 需要进行移位
    if(exp)
    {
        if(flag)    //如果指数为负数，向右移位
        {
            printf("0.");
            while(--exp)    printf("0");
            for(int k = 0; k<len_base; k++)    printf("%c",base[k] );
        }
        else    //指数为正数，向左移位
        {
            if(exp < len_base-1) //移位后还需要输出小数点
            {
                //注意index作用域，开始误写成int index = 0, 结果对输入
                //-3.1415926E+4会输出-31415.31415926
                for(index = 0; index<= exp; index++)    printf("%c",base[index] );
                printf(".");
                for(; index < len_base; index++)   printf("%c",base[index] );
            }
            else    //移位后不用输出小数点
            {
                for(int k = 0; k < len_base; k++)  printf("%c",base[k] );
                for(int k = 0 ; k < exp - len_base+1; k++)   printf("0");
            }
        }
    }
    //如果exp为0，不用移位，直接输出
    else
    {
        for(int k = 1; str[k] != 'E'; k++)
            printf("%c",str[k] );
    }
    return 0;
}
