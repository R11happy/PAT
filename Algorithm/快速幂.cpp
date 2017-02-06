// b少于6位的情况
typedef long long LL;
LLpow(LL a, LL b, LL m)
{
    LL ans = 1;
    for(int i = 0; i<b; i++)
    {
        ans = ans * a % m;
    }
    return ans;
}

// b少于18位的情况
/*递归方法*/
typedef long long LL;
//////////////////
//求a^b % m的递归写法 //
//////////////////
LL binaryPow(LL a, LL b, LL m)
{
    if(b == 0)  return 1;   //如果b为0，那么a^0 = 1;
    //b为奇数，转换为b-1， 可以写成b&1
    if(b % 2 == 1)  return a * binaryPow(a, b-1, m)%m;
    else    //b为偶数，转换为b/2
    {
        LL mul = binaryPow(a, b/2, m);
        return mul * mul % m;   //要先求出结果存到mul中，不然求两次再取平方会退化到O(b)
    }
}
/*
1.如果初始时a有可能大于等于m，那么需要在进入函数之前就让a对m取模
2.如果m为1，可以直接在函数外部特判为0，不需要进入函数来计算(任何正整数对1取模一定等于0)
 */

/*迭代写法*/
typedef long long LL;
//////////////////
//求a^b % m的迭代写法 //
//////////////////

LL binaryPow(LL a, LL b, LL m)
{
    LL ans = 1;
    while(b > 0)
    {
        if(b & 1)   //如果b的二进制末尾为1(也可以携程if(b%2))
        {
            ans = ans * a % m;  //令ans累积上a
        }
        a = a * a % m;  //令a平方
        b >>= 1;    //将b的二进制右移1位，即 b = b >> 1或 b /= 2
    }
    return ans;
}
