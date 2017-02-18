/**
* @tag     PAT_A_1081
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-18 15:14-15:49
* @version 1.0
* @Language C++
* @Ranking  1360/986
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Fraction
{
    LL up, down;
};

LL gcd(LL a, LL b)
{
    if (b == 0)  return a;
    else return gcd(b, a%b);
}

Fraction reduction(Fraction a)
{
    if (a.down < 0)
    {
        a.up = -a.up;
        a.down = -a.down;
    }
    if (a.up == 0)   a.down = 1;
    else {
        LL d = gcd(a.down, a.up);
        a.up /= d;
        a.down /= d;
    }
    return a;
}

void showResult(Fraction res)
{
    res = reduction(res);
    if (res.down == 1)   printf("%lld\n", res.up);
    else if (abs(res.up) > abs(res.down))
    {
        printf("%lld %lld/%lld\n", res.up / res.down, abs(res.up) % abs(res.down), res.down);
    }
    else printf("%lld/%lld\n", res.up, res.down);
}

Fraction add(Fraction a, Fraction b)
{
    Fraction res;
    res.down = a.down * b.down;
    res.up = a.up*b.down + a.down*b.up;
    return reduction(res);
    showResult(res);
}

int main(int argc, char const *argv[])
{
    int N;
    Fraction tmp, res;
    res.up = 0, res.down = 1;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        res = add(tmp, res);
    }
    showResult(res);
    return 0;
}
