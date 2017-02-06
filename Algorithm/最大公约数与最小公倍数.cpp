////////////
// 求最大公约数 //
// ////////////
int gcd(int a, int b)
{
    if(b == 0)  return a;
    else    return gcd(b, a%b);
}

// 最小公倍数
lcm = a / gcd * b
