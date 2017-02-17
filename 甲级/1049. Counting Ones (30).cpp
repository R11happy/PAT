/**
* @tag     PAT_1104
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-17
* @version 1.0
* @Language C++
* @Ranking  20:48-22:36
* @function 1340/1015
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int digitOne[10010];
int digit[10010];
int len;

void init(int num)
{
    do {
        digit[len++] = num % 10;
        num /= 10;
    } while (num != 0);
}

// 将数组的数转化为数字
int toNum(int A[], int start, int end)
{
    int numAns = 0;
    while (start<end)
    {
        numAns = numAns * 10 + A[start++];
    }
    return numAns;
}

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    init(num);
    reverse(digit, digit + len);
    int ans = 0;
    int product = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        int left = toNum(digit, 0, i);
        int right = toNum(digit, i+1, len);
        if (digit[i] > 1)
        {
            digitOne[i] = (left + 1)*product;
        }
        else if (digit[i] == 1)
        {
            digitOne[i] = left*product + right + 1;
        }
        else
        {
            digitOne[i] = left*product;
        }
        product *= 10;
    }
    for (int i = 0; i<len; i++)
    {
        ans += digitOne[i];
    }
    printf("%d\n",ans );
    return 0;
}


