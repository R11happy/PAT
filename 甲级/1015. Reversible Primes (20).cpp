/**
* @tag     PAT_A_1015
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-18 16:33-18:11
* @version 1.0
* @Language C++
* @Ranking  1400/946
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int prime[maxn], pNum;
bool p[maxn] = { 1,1 }; //注意，做筛表要将p[0],p[1]设置为true

// 打表找素数
void findPrime()
{
    for (int i = 2; i<maxn; i++)
    {
        if (p[i] == false)
        {
            prime[pNum++] = i;
            for (int j = i + i; j<maxn; j += i)
            {
                p[j] = true;
            }
        }
    }
}

int str[20];
// 转换成对应进制，每一位存到数组中并返回长度
int toRadix(int str[], int num, int radix)
{
    int len = 0;
    do {
        str[len++] = num%radix;
        num /= radix;
    } while (num != 0);
    return len;
}
// 根据数组，算出对应10进制的数并返回
int toDecimal(int str[], int radix, int len)
{
    int ans = 0, product = 1;
    for (int i = 0; i<len; i++)
    {
        ans = ans + product*str[i];
        product *= radix;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int N, radix;
    findPrime();
    scanf("%d", &N);
    while (N >= 0)
    {
        scanf("%d", &radix);
        memset(str, 0, sizeof(str));
        int flag = 0;
        if (p[N] == false)
        {
            int len = toRadix(str, N, radix);
            reverse(str, str + len);
            int num = toDecimal(str, radix, len);
            if (p[num] == false) flag = 1;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
        scanf("%d", &N);
    }
    return 0;
}
