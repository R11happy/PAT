/**
* @tag     PAT_A_1101
* @authors R11happy (xushuai100@126.com)
* @date
* @version 1.0
* @Language C++
* @Ranking  1290/1059
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = (1<<31)-1;

int a[MAXN], leftMax[MAXN], rightMin[MAXN];
int ans[MAXN], num = 0;

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    leftMax[0] = 0; //A[0]左边没有比它大的数
    for(int i = 1; i<n; i++)
    {
        leftMax[i] = max(leftMax[i-1], a[i-1]); //递推
    }
    rightMin[n-1] = INF;
    for(int i = n-2; i>=0; i--)
    {
        rightMin[i] = min(rightMin[i+1], a[i+1]);
    }
    // 记录主元
    for(int i = 0; i<n; i++)
    {
        // 左边所有数，右边所有数比它大
        if(leftMax[i] < a[i] && rightMin[i] > a[i])
        {
            ans[num++] = a[i];  //记录主元
        }
    }
    printf("%d\n", num );   //输出主元个数
    for(int i = 0; i<num; i++)
    {
        printf("%d", ans[i] );    //依次输出所有主元
        if(i < num-1) printf(" ");
    }
    printf("\n");
    return 0;
}
