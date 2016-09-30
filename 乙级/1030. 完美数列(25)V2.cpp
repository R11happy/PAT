/**
* @tag     PAT_B_1030
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-5 16:44-17:44
* @version 1.0
* @Language C++
* @Ranking  715/651
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int Max = 100000; //段错误，先判断数组是不是开小了



int main(int argc, char const *argv[])
{
    int num[Max+10];
    int N;
    long long x, p;
    int res, maxn = 0;
    scanf("%d %d",&N, &p );
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num+N);   //组成递增序列
    for(int i = 0; i < N; i++)
    {
        x = num[i] * p; //这里，x可能达到18位数,但要保证x存储正确的long long 类型，p也必须是long long 类型
        res = upper_bound(num+i,num+N, x) - num;    //第一个满足M>m*p的前一位为最后一个满足M<=m*p的，减一个1，再加一个1，相当于抵消
        if(res > maxn)   maxn = res;
    }
    printf("%d\n",maxn );
    return 0;
}
