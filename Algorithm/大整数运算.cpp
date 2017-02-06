struct bign
{
    int d[1000];
    int len;
    // 保证每次定义结构体变量时，都会自动对该变量进行初始化
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

// 将整数转化为bign
bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for(int i = 0; i<a.len; i++)
    {
        a.d[i] = str[a.len - 1 - i] - '0';  //逆着赋值
    }
    return a;
}

// 比较两个bign变量的大小
int compare(bign a, bign b) //比较a和b的大小
// a大 返回1
// a等 返回0
// a小 返回-1
{
    if(a.len > b.len )  return 1;
    else if(a.len < b.len)  return -1;
    else
    {
        for(int i = a.len - 1; i>=0; i--)   //从高位往低位比较
        {
            if(a.d[i] > b.d[i])     return 1;   //a大
            else if(a.d[i] < b.d[i])    return -1;  //a小
        }
        return 0;   //a == b
    }
}

// 高精度a+b
bign add(bign a, bign b)
{
    bign c;
    int carry = 0;  //进位
    for(int i=0; i<a.len || i<b.len; i++)   //以较长的为界限
    {
        int temp = a.d[i] + b.d[i] + carry; //两个对应位与进位相加
        c.d[c.len++] = temp % 10;   //个位数为该位结果
        carry = temp / 10;  //十位数为新的进位
    }
    if(carry != 0)  //如果最后进位不为0，则直接赋值给结果的最高位
    {
        c.d[c.len++] = carry;
    }
    return c;
}

// 高精度a-b
bign sub(bign a, bign b)
{
    bign c;
    for(int i = 0; i<a.len || i<b.len; i++)
    {
        if(a.d[i] < b.d[i])
        {
            a.d[i+1]--; //向高位借位
            a.d[i] += 10;   //当前位加10
        }
        c.d[len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;    //去除高位的0,同时至少保留一位最低位
    }
    return c;
}

bign mul(bign a, int b)
{
    bign c;
    int carry = 0;  //进位
    for(int i = 0; i<a.len; i++)
    {
        int temp = a.d[i]*b+carry;
        c.d[c.len++] = temp % 10;   //个位作为该位结果
        carry = temp / 10;
    }
    while(carry != 0)   //乘法的进位可能不只一位
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}


bign div(bign a, int b, int& r)
{
    bign c;
    // 被除数的每一位和商的每一位是一一对应的
    int carry = 0;
    for(int i = a.len-1; i>=0; i--)
    {
        r = r*10 + a.d[i];  //和上一位遗留的余数组合
        if(r < b)   c.d[i] = 0; //不够除，该位0
        else
        {
            c.d[i] = r / b; //商
            r = r % b;  //余数
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len - 1] == 0)
    {
        c.len--;    //去除高位的0,同时至少保留一位最低位
    }
    return c;
}
