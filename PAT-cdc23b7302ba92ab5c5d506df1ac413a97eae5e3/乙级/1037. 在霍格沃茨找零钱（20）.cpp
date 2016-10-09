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

int main(int argc, char const *argv[])
{
    int Knut1, Sickle1, Galleon1;
    int Knut2, Sickle2, Galleon2;
    int Knut, Sickle, Galleon;  //用来输出
    scanf("%d.%d.%d", &Galleon1, &Sickle1, &Knut1);
    scanf("%d.%d.%d", &Galleon2, &Sickle2, &Knut2);
    Knut1 = (Galleon1*17 + Sickle1)*29 + Knut1;
    Knut2 = (Galleon2*17 + Sickle2)*29 + Knut2;
    int flag = 0;   //负数时为1
    int sub = Knut2 - Knut1;
    if(sub < 0)
    {
        flag = 1;
        sub = Knut1 - Knut2;
    }
    Galleon = sub / 17 / 29;
    Sickle = (sub - Galleon*17*29)/29;
    Knut = sub - (Galleon*17 + Sickle)*29;
    if(flag)
        printf("-%d.%d.%d\n",Galleon,Sickle,Knut );
    else
        printf("%d.%d.%d\n",Galleon,Sickle,Knut );

    return 0;
}
