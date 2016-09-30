/**
* @tag     PAT_B_1037
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-16 19:16-19:31
* @version 1.0
* @Language C++
* @Ranking  330/2139
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Galleon = 17 * 29;
const int Sickle  = 29;

int main(int argc, char const *argv[])
{
    int a1, b1, c1;
    int a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2 );
    int price = a1 * Galleon + b1 * Sickle + c1;
    int money = a2 * Galleon + b2 * Sickle + c2;
    int change = money - price; //找零的钱
    if(change < 0)
    {
        printf("-");
        change = -change;
    }
    printf("%d.%d.%d\n", change / Galleon, change % Galleon / Sickle, change % Sickle);

    return 0;
}
