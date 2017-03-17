/**
* @tag     PAT_A_1007
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-17 15:58
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 10010;
int A[maxn],dp[maxn];
int start[maxn] = {0};
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int flag = false;   //记录是否全为负数
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
        if(A[i] >= 0)   flag = true;
    }
    if(!flag)
    {
        printf("0 %d %d\n", A[0], A[n-1]);
        return 0;
    }
    else
    {
        dp[0] = A[0];
        for(int i = 1; i<n; i++)
        {
            if(dp[i-1] + A[i] > A[i])
            {
                start[i] = start[i-1];
                dp[i] = dp[i-1] + A[i];
            }
            else
            {
                start[i] = i;
                dp[i] = A[i];
            }
        }
        int k = 0;
        for(int i = 1; i<n; i++)
        {
            if(dp[i] > dp[k])
            {
                k = i;
            }
        }
        printf("%d %d %d\n",dp[k], A[start[k]], A[k] );
    }

    return 0;
}
