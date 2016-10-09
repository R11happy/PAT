/**
* @tag     PAT_A_1058
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-20 00:13-00:27
* @version 1.0
* @Language C++
* @Ranking  280/2992
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Galleon = 29*17;
const int Sickle = 29;

typedef long long LL;
int main(int argc, char const *argv[])
{
    LL a1, b1, c1;  //如果用int类型会导致测试点3错误
    LL a2, b2, c2;
    LL sum;
    scanf("%lld.%lld.%lld", &a1, &b1, &c1);
    scanf("%lld.%lld.%lld", &a2, &b2, &c2);
    sum = (a1*Galleon+b1*Sickle+c1) + (a2*Galleon+b2*Sickle+c2);
    printf("%d.%d.%d\n",int(sum / Galleon), int(sum % Galleon / Sickle), int(sum % Sickle) );
    return 0;
}
