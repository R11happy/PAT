/**
* @tag     PAT_B_1045
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 18:35-19:12
* @version 1.0
* @Language C++
* @Ranking  790/559
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000;
long long origin[maxn], changed[maxn], output[maxn];

int main(int argc, char const *argv[])
{
    int cnt = 0,N;
    long long max = 0L;
    scanf("%d", &N);
    for(int i = 0; i<N;  i++)
    {
        scanf("%lld", &origin[i]);
        changed[i] = origin[i];
    }
    sort(changed, changed+N);
    // 考虑1 4 3 2 5中的3
    // 只有与实际位置温吻合，并且前面没有更大的数的时候才可能是主元
    for(int i = 0; i<N; i++)
    {
        if(origin[i] == changed[i] && max < origin[i] )
        {
            output[cnt++] = changed[i];
        }
        if(max < origin[i]) max = origin[i];
    }

    printf("%d\n",cnt );
    for(int i = 0; i < cnt; i++ )
    {
        if(i < cnt -1)
        {
            printf("%lld ",output[i] );
        }
        else printf("%lld",output[i] );
    }
    printf("\n");   //当cnt为0时候，也要换行，不然会显示格式错误
    return 0;
}
