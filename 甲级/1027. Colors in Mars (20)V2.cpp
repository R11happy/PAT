/**
* @tag     PAT_A_1027
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-19 23:29-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    char radix13[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A','B','C'};
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    printf("#");
    printf("%c%c",radix13[r/13], radix13[r%13] );
    printf("%c%c",radix13[g/13], radix13[g%13] );
    printf("%c%c",radix13[b/13], radix13[b%13] );
    return 0;
}
