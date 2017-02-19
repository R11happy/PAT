/**
* @tag     PAT_A_
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-11 3:30-3:54
* @version 1.0
* @Language C++
* @Ranking  540/1934
* @function null
*/



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int prime[maxn], pNum;
bool p[maxn] = { 0 };

void Find_Prime()
{
    for (int i = 2; i < maxn; i++)
    {
        if (p[i] == false)
        {
            prime[pNum++] = i;
            for (int j = i + i; j < maxn; j += i)
            {
                p[j] = true;
            }
        }
    }
}

struct factor
{
    long long x;
    int cnt = 0;
}fac[10];

int main()
{
    long long N;
    int num = 0;
    scanf("%lld", &N);
    Find_Prime();
    if (N == 1) printf("1=1");  //注意特判
    else
    {
        printf("%lld=",N);
        int sqr = (int)sqrt(1.0*N);
        for (int i = 0; i < pNum && prime[i] <= sqr; i++)
        {
            if (N % prime[i] == 0)
            {
                fac[num].x = prime[i];
                while (N % prime[i] == 0)
                {
                    fac[num].cnt++;
                    N /= prime[i];
                }
                num++;
            }
            if (N == 1) break;
        }
        if (N != 1)
        {
            fac[num].x = N;
            fac[num++].cnt++;   //不是fac[num].cnt++
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (i > 0)  printf("*");
        printf("%lld", fac[i].x);
        if (fac[i].cnt > 1) printf("^%d", fac[i].cnt);
    }
    return 0;
}



