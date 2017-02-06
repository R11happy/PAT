///////////
// 分数的表示 //
// ///////////

struct Fraction
{
    int up, down;
};

/*规则
    1.使down为非负数。如果分数为负，那么令分子up为负即可
    2.如果该分数恰为0，那么规定其分子为0，分母为1
    3.分子和分母没有除了1以外的公约数
*/


///////////
// 分数的化简 //
// ///////////
// 以下四则运算请均保证除数不为0

/*规则
    1.如果分母down为负数，那么令分子up和分母down都变为相反数
    2.如果分子up为0，那么令分母down为1
    3.约分：求出分子绝对值与分母绝对值的最大公约数d，然后令分子分母同时除以d
*/

Fraction reduction(Fraction result)
{
    if(result.down < 0) //分母为负数，令分子分母都变为相反数
    {
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up == 0)  //分子为0
    {
        result.down = 1;    //令分母为1
    }
    else    //如果分子不为0，进行约分
    {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d; //约去最大公约数
        result.down /= d;
    }
    return result;
}

/*分数的加法*/
Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down + f1.down*f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/*分数的减法*/
Fraction sub(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up*f2.down - f1.down*f2.up;
    result.down = f1.down * f2.down;
}

/*分数的乘法*/
Fraction mul(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/*分数的除法*/
Fraction div(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

/*分数的输出*/
// 一般情况，分子分母用long long 类型存储
void showResult(Fraction r)
{
    r = reduction(r);
    if(r.down == 1) printf("%lld",r.up);    //整数
    else if(abs(r.up) > r.down)             //假分数
    {
        printf("%d %d/%d",r.up/r.down, abs(r.up)%r.down, r.down );
    }
    else    printf("%d/%d",r.up,r.down );   //真分数
}
