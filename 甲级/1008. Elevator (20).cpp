/**
* @tag     PAT_A_1008
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-17 19:53-20:06
* @version 1.0
* @Language C++
* @Ranking  1310/1044
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int efloor[maxn];

int main(int argc, char const *argv[])
{
    int N;
    int ans = 0;
    scanf("%d", &N);
    ans = N*5;
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &efloor[i]);
        if(efloor[i] > efloor[i-1])   ans += (efloor[i] - efloor[i-1])*6;
        else    ans += (efloor[i-1] - efloor[i])*4;
    }
    printf("%d\n",ans );
    return 0;
}
