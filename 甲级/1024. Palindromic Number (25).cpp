/**
* @tag     PAT_A_1024
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-20 17:08-17:49
* @version 1.0
* @Language C++
* @Ranking  1490/864
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPalindromic(int str[], int len)
{
    for (int i = 0; i <= len / 2; i++)
    {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}

struct bign
{
    int d[1000];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[])
{
    int len = strlen(str);
    bign res;
    for (int i = 0; i<len; i++)
    {
        res.d[i] = str[len - 1 - i] - '0';
        res.len++;
    }
    return res;
}

bign add(bign a, bign b)
{
    bign c;
    int carry = 0;
    for (int i = 0; i<a.len || i<b.len; i++)
    {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    // 不要忘记处理最后carry不等于0的情况
    if (carry != 0)
    {
        c.d[c.len++] = carry;
    }
    return c;
}

char str[25];


int main(int argc, char const *argv[])
{
    int K = 0;
    int step = 0;
    scanf("%s %d", str, &K);
    bign origin = change(str);
    for (step = 0; step < K; step++)
    {
        if (isPalindromic(origin.d, origin.len) == true) break;
        else
        {
            bign tmp = origin;
            reverse(tmp.d, tmp.d + tmp.len);
            origin = add(origin, tmp);
        }
    }
    int len = origin.len;
    for (int i = 0; i<len; i++)
    {
        printf("%d", origin.d[len - 1 - i]);
    }
    printf("\n");
    printf("%d\n", step);
    return 0;
}
