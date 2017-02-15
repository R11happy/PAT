/**
* @tag     PAT_A_1010
* @authors R11happy (xushuai100@126.com)
* @date    2017 2-15 19:34-23:20
* @version 1.0
* @Language C++
* @Ranking  1190/1158
* @function null
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL Map[256]; //0~9,a~z与0~35的对应
LL inf = (1LL << 63) - 1;   //long long 的最大值

void init()
{
    for (char c = '0'; c <= '9'; c++)
    {
        Map[c] = c - '0';   //将'0'~'9'映射到0~9
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        Map[c] = c - 'a' + 10;  //将'a'~'z'映射到10~35
    }
}
// 将a转化为10进制数
LL convertToDecimal(char a[], LL radix, LL max)
{
    LL ans = 0;
    LL product = 1;
    int len = strlen(a);
    for(int i = len-1; i>=0; i--)
    {
        ans += Map[a[i]]*product;
        product *= radix;
        if(ans > max || ans < 0) return -1; //溢出或超过N1的十进制
    }
    return ans;
}
// 寻找对应数值最大的位，用于确定下界
int findMaxDigit(char a[])
{
    int ans = -1;
    int len = strlen(a);
    for(int i = 0; i<len; i++)
    {
        if(Map[a[i]] > ans) ans = Map[a[i]];
    }
    return ans+1;
}

int cmp(char N2[], LL radix, LL max)
{
    LL num = convertToDecimal(N2, radix, max);
    if(num == max)  return 0;   //N2 == N1
    else if(num == -1 || num > max)  return 1;  //N2 > N1
    else return -1; //N2 < N1
}

// 二分法寻找radix，因为radix越大，代表的数值也越大
LL binarySearch(char N2[], LL left, LL right, LL val)
{
    LL mid;
    while(left <= right)
    {
        mid = left + (right - left)/2;
        int flag = cmp(N2, mid, val);
        if(flag == 0)   return mid;
        else if(flag > 0) right = mid-1;
        else left = mid+1;
    }
    return -1;
}
char N1[20], N2[20];

int main(int argc, char const *argv[])
{
    init();
    int tag, radix;
    scanf("%s %s %d%d", N1, N2, &tag, &radix);
    if(tag == 2) swap(N1, N2);
        // 将N1转换为10进制
    LL N1Decimal = convertToDecimal(N1, radix, inf);
    LL low = findMaxDigit(N2); //二分下界
    LL high = max(low,N1Decimal)+1; //二分上界
    LL ans = binarySearch(N2, low, high, N1Decimal);
    if(ans == -1)   printf("Impossible\n");
    else printf("%lld\n",ans );
    return 0;
}
