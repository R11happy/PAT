/**
* @tag     PAT_A_1046
* @authors R11happy (xushuai100@126.com)
* @date    2016-07-20 20:30:16-21:04
* @version 1.0
* @Language C++
* @Ranking  40/6605
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>    //要用到swap和min函数
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;   //100000另一种表达 1e5

int dist[MAXN];    //dist[i]存放第1号节点，顺时针到达第i号节点下一节点的距离
int main()
{
    ll N, M, sum = 0;
    ll clockwise = 0;    //记录顺时针的距离
    int temp, first, second;
    scanf("%lld", &N);      //注意long long 一定要用%lld,不然会直接跳出
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &temp);
        sum += temp;
        dist[i] = sum;  //输入的时候就记录1节点到每个节点的距离
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &first, &second);
        if (first > second)
        {
            swap(first, second);
        }
        clockwise = dist[second - 1] - dist[first - 1]; //得到顺时针的距离
        printf("%d\n", min(clockwise, sum - clockwise));    //用总距离-顺时针距离得到逆时针距离
                                                            //选顺时针和逆时针距离中小的那一个
    }
    return 0;
}
