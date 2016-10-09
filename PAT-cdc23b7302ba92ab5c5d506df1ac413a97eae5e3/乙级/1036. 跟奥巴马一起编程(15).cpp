/**
* @tag     PAT_B_1036
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-14 4:49-5:00
* @version 1.0
* @Language C++
* @Ranking  270/2573
* @function null
*/

#include <cstdio>
#include <csdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int row, col;
    char ch;
    scanf("%d %c", &row, &ch);
    if((row/2*2) == row )   col = row / 2;
    else    col = row / 2 +1;

    for(int i=0; i<row; i++)
        printf("%c",ch );
    printf("\n");
    for(int i = 0; i<col-2; i++)
    {
        printf("%c", ch );
        for(int j = 2; j<row; j++)
            printf(" ");
        printf("%c\n",ch );
    }
    for(int i=0; i<row; i++)
        printf("%c",ch );
    printf("\n");
    return 0;
}
