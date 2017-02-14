/**
* @tag     PAT_A_1044
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-14 19:06-20:23
* @version 1.0
* @Language C++
* @Ranking  1165/1182
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int sum[maxn];

// 返回[L,R)内，第一个大于等于x的位置
int low_bound(int L, int R, int x)
{
    int left = L, right = R, mid;
    while(left < right)
    {
        mid = left + (right - left)/2;
        if(x <= sum[mid])    right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d%d", &N, &M);
    int sumOfSubsequence = 100010;
    for(int i = 1; i<=N; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int j;  //右边界下标;
    for(int i = 0; i<N; i++)    //遍历左边界
    {
        j = low_bound(i, N, sum[i]+M);
        if(sum[j] - sum[i] == M)
        {
            sumOfSubsequence = M;
            break;
        }
        else if(sum[j] - sum[i] - M > 0 &&sum[j] - sum[i] < sumOfSubsequence)   sumOfSubsequence = sum[j] - sum[i];
    }
    for(int i = 0; i<N; i++)
    {
        j = low_bound(i,N, sum[i]+M);
        if(sum[j] - sum[i] == sumOfSubsequence)
        {
            printf("%d-%d\n",i,j );
        }
    }

    return 0;
}
