////////////
///////// //
////// // //
// 质因子分解 // // //
////// // //
///////// //
////////////

/**
 * 对一个正整数n来说，如果它存在[2,n]范围内的质因子，要么这些质因子全部小于等于sqrt(n),要么只存在一个大于sqrt(n)的质因子，而其余质因子全部小于等于sqrt(n)
 */

struct factor
{
    int x, cnt; //x为质因子，cnt为其个数
}fac[10];

// 1.枚举1~sqrt(n)范围内的所有质因子p, 判断p是否是n的因子
if(n%prime[i] == 0)
{
    fac[num].x = prime[i];
    fac[num].cnt = 0;
    // 计算质因子prime[i]的个数
    while(n % prime[i] == 0)
    {
        fac[num].cnt++;
        n /= prime[i];
    }
}
// 2.如果在上面步骤结束后n仍然大于1,这时需要把这个质因子加入fac数组，并令其个数为1
if(n!=1)
{
    fac[num].x = n;
    fac[num++].cnt = 1;
}

