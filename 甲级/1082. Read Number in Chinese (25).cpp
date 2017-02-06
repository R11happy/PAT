/**
* @tag     PAT_A_1082
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-6 19:11-19:47
* @version 1.0
* @Language C++
* @Ranking  755/1738
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] ={
    "Shi", "Bai", "Qian","Wan", "Yi"
};
int main(int argc, char const *argv[])
{
    char str[15];
    gets(str);
    int len = strlen(str);
    int left = 0, right = len - 1;
    if(str[0] == '-')
    {
        printf("Fu");
        left++;
    }
    while(left+4 <= right)  right-=4;
    while(left < len)
    {
        bool flag = false; //flag == false表示没有累积的0
        bool isPrint = false;   //flag == false表示该节没有输出过其中的位
        while(left <= right)
        {
            if(left > 0 && str[left] == '0')  //如果当前位为0
            {
                flag = true;
            }
            else    //如果当前位不为0
            {
                if(flag == true)
                {
                    printf(" ling");
                    flag = false;
                }
                if(left > 0)    printf(" ");
                printf("%s",num[str[left] - '0'] ); //输出当前位数字
                isPrint = true; //该节至少有一位被输出
                if(left != right)   //某节中除了个位外，都需要输出十百千
                {
                    printf(" %s",wei[right - left -1] );
                }
            }
            left++;
        }
        if(isPrint == true && right != len-1)   //只要不是个位，就输出万或者亿
        {
            printf(" %s",wei[(len-1-right)/4 +2] );
        }
        right += 4;
    }
    return 0;
}
