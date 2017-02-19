/**
* @tag     PAT_A_1096
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-19 14:32-15:12
* @version 1.0
* @Language C++
* @Ranking  1445/903
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main(int argc, char const *argv[])
{
    LL N;
    scanf("%lld", &N);
    int maxLen = 0;
    int index = 0;
    LL sqr = (LL)sqrt(1.0*N);
    for(int i = 2; i<=sqr; i++)
    {
        int curLen = 0;
        LL tmp = i;
        if(N % i == 0)
        {
            curLen++;
            for(int j = i+1; j<=sqr; j++)
            {
                tmp*=j;
                if(N % tmp==0) curLen++;
                else break;
            }
            if(curLen > maxLen)
            {
                index = i;
                maxLen = curLen;
            }
        }
    }
    if(maxLen == 0)
    {
        printf("1\n");
        printf("%lld\n",N );
    }
    else
    {
        printf("%d\n",maxLen );
        for(int i = 0; i<maxLen-1; i++)
        {
            printf("%d*", index+i);
        }
        printf("%d\n",index+maxLen-1 );
    }

    return 0;
}
