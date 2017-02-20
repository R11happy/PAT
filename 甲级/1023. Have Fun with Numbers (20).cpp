/**
* @tag     PAT_A_1023
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-20 16:01-16:40
* @version 1.0
* @Language C++
* @Ranking  1465/894
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

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
    bign re;
    int len = strlen(str);
    for (int i = 0; i<len; i++)
    {
        re.d[len - 1 - i] = str[i]-'0'; //注意：要将char转化为int类型，需要-'0'，不要忘记
        re.len++;
    }
    return re;
}

bign mul(bign a, int b)
{
    int carry = 0;
    bign c;
    for (int i = 0; i<a.len; i++)
    {
        int temp = a.d[i] * b + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0)
    {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}

char str[1000];
int hashTable[20];

int main(int argc, char const *argv[])
{
    int flag = 0;
    gets(str);
    bign a = change(str);
    for (int i = 0; i<a.len; i++)
    {
        hashTable[a.d[i]]++;
    }
    bign b = mul(a, 2);
    if (a.len != b.len) flag = 1;
    else
    {
        for (int i = 0; i<b.len; i++)
        {
            --hashTable[b.d[i]];
        }
        for (int i = 0; i <= 9; i++)
        {
            if (hashTable[i] != 0)
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag) printf("Yes\n");
    else printf("No\n");
    for (int i = b.len - 1; i >= 0; i--)
    {
        printf("%d", b.d[i]);
    }
    printf("\n");
    return 0;
}
