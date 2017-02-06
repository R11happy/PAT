/**
* @tag     PAT_B_1034
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-8 19:29-22:04
* @version 1.0
* @Language C++
* @Ranking  890/371
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>    //头文件不能用<cmath>,用<algorithm>才能过
using namespace std;
typedef long long LL;

struct Fraction
{
    LL up, down;
}a, b;

LL gcd(LL a, LL b)
{
    if (b == 0)  return a;
    else return gcd(b, a%b);
}
//分数化简
Fraction reduction(Fraction result)
{
    if (result.down < 0)
    {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
    {
        result.down = 1;
    }
    else
    {
        LL d = gcd(abs(result.up), abs(result.down));   //要计算绝对值的公约数
        result.up /= d;
        result.down /= d;
    }
    return  result;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down + f2.up*f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction sub(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down - f2.up*f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction mul(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction div(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r)
{
    r = reduction(r);
    if (r.up < 0)   printf("(");
    if (r.down == 1) printf("%lld", r.up);
    else if (abs(r.up) > r.down)   printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);    //是else if 不是 if 而且abs不能少
    else
        printf("%lld/%lld", r.up, r.down);
    if (r.up < 0)    printf(")");
}

int main(int argc, char const *argv[])
{
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    // 加
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");
    // 减
    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(sub(a, b));
    printf("\n");
    //乘
    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(mul(a, b));
    printf("\n");
    // 除
    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0)   printf("Inf");
    else showResult(div(a, b));
    printf("\n");
    return 0;
}
