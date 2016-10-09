/**
* @tag     PAT_B_1010
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-23 19:00:17-19:08
* @version 2.0
* @Language C++
* @Ranking  180/3621
*/

#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int epo, cof;
    bool flag = false;
    while(scanf("%d%d", &cof, &epo) != EOF)
    {
        if(cof*epo)
        {
            if(flag)
                printf(" ");
            else
                flag = true;
            printf("%d %d", cof*epo, epo-1);
        }
    }
    if(!flag)
        printf("0 0");
}
