/**
* @tag     PAT_B_1007
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-8 22:45-22:57
* @version 1.0
* @Language C++
* @Ranking  910/328
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
//
//对每一个素数p，判断p-2是不是同样是素数，是的话计数器加1
int Find_Prime(int N)
{
    int cnt = 0;
    for(int i = 2; i<=N; i++)
    {
        if(p[i] == false)
        {
            prime[pNum++] = i;
            if(i>3 && p[i-2] == false)  cnt++;
            for(int j = i+i; j<=N; j+=i)
            {
                p[j] = true;
            }
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    printf("%d\n",Find_Prime(N) );
    return 0;
}
