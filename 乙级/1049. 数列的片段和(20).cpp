/**
* @tag     PAT_B_1049
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-7 23:47-00:30
* @version 1.0
* @Language C++
* @Ranking  850/423
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    double ans = 0.0;
    double tmp = 0.0;
    double pass[100010]={0.0};
    scanf("%d", &N);
    for(int i = 1; i<=N; i++)
    {
        scanf("%lf", &tmp);
        ans += tmp*i*(N-i+1);   //找每个位置数字出现次数的规律
    }
    printf("%.2f\n",ans);
    return 0;
}
