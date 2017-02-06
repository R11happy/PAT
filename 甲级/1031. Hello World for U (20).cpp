/**
* @tag     PAT_A_1031
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-15 15:42-16:02
* @version 1.0
* @Language C++
* @Ranking  220/3486
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    char str[100];
    gets(str);
    int len = strlen(str);
    int H = (len+2)/3-1;    //n1-1
    int bottom = (len+2)/3; //n2
    int remainder = (len+2)%3;
    if(remainder == 1)  bottom++;   //n2修正
    else if(remainder == 2) bottom+=2;  //n2修正
    else ;
    int i;
    for(i=0; i<H; i++)
    {
        printf("%c",str[i] );   //打印左侧字符
        for(int j=0; j<(bottom-2); j++)
        {
            printf(" ");
        }
        printf("%c\n",str[len-i-1] );   //打印右侧字符
    }
    //打印底部字符
    for(int k=0; k<bottom; k++,i++ )
    {
        printf("%c",str[i] );
    }
    printf("\n");
    return 0;
}



