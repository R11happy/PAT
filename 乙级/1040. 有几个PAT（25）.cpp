/**
* @tag     PAT_B_1040
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 17:58-18：20
* @version 1.0
* @Language C++
* @Ranking  765/583
* @function null
*/

//sum of 每个'A' 左边'P'个数 * 右边'T'个数

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
using namespace std;

const int  maxn = 100000;
char str[maxn];
const long long MOD = 1000000007;

int main(int argc, char const *argv[])
{
    long long sum_T = 0L;
    long long left_P = 0L, right_T = 0L;
    long long ans = 0L;
    gets(str);
    int len = strlen(str);
    //统计总的'T'个数
    for(int i = 0; i<len; i++)
    {
        if(str[i] == 'T')   sum_T++;
    }
    for(int i = 0; i<len; i++)
    {
        if(str[i] == 'P')   left_P++;   //'A'左边'P'的个数
        else if(str[i] == 'A')
        {
            ans += left_P * (sum_T - right_T) % MOD;
            ans = ans % MOD;
        }
        else    right_T++;  //'A'左边'T'的个数
    }
    printf("%lld\n",ans );
    return 0;
}
