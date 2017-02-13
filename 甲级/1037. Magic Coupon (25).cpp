/**
* @tag     PAT_A_1037
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-13 18:53-19:29
* @version 1.0
* @Language C++
* @Ranking  1085/1256
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
long long coupon[maxn];
long long product[maxn];

bool cmp(long long a, long long b)
{
    return a>b;
}

int main(int argc, char const *argv[])
{
    int NC, NP;
    int headC = 0, headP = 0;
    scanf("%d", &NC);
    long long ans = 0;
    for (int i = 0; i<NC; i++)
    {
        scanf("%lld", &coupon[i]);
    }
    scanf("%d", &NP);
    for (int i = 0; i<NP; i++)
    {
        scanf("%lld", &product[i]);
    }
    int tailC = NC - 1, tailP = NP - 1;
    sort(coupon, coupon + NC);
    sort(product, product + NP);
    while (headC <= tailC && headP <= tailP)
    {
        int nowMax = 0, flag = 0;
        long long head = coupon[headC] * product[headP];
        long long tail = coupon[tailC] * product[tailP];
        if (head > nowMax)
        {
            nowMax = head;
            flag = 1;
        }
        if (tail > nowMax)
        {
            nowMax = tail;
            flag = 2;
        }
        if (flag == 0)   break;  //ans无法增加，跳出
        ans += nowMax;
        if (flag == 1)
        {
            headC++;
            headP++;
        }
        else
        {
            tailC--;
            tailP--;
        }

    }
    printf("%lld\n", ans);
    return 0;
}
