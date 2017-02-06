/**
* @tag     PAT_B_1017
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-10 22:16-
* @version 1.0
* @Language C++
* @Ranking  930/309
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int r;  //用作余数
struct bign
{
    int d[1000];
    int len;
    bign()
    {
        fill(d,d+sizeof(d)/sizeof(d[0]),0); //或memset(d,0,sizeof(d))
        len = 0;
    }
};

bign change(char str[])
{
    bign a;
    a.len = strlen(str);
    for (int i = 0; i<a.len; i++)
    {
        a.d[i] = str[a.len - 1 - i] - '0';
    }
    return a;
}

int compare(bign a, bign b)
{
    if (a.len > b.len)   return 1;
    else if (a.len < b.len)  return -1;
    else
    {
        for (int i = a.len - 1; i >= 0; i--)
        {
            if (a.d[i] > b.d[i])   return 1;
            else if (a.d[i] < b.d[i])   return -1;
        }
    }
    return 0;
}

bign div(bign a, int b)
{
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--)
    {
        r = r * 10 + a.d[i];
        c.d[i] = r / b;
        r = r % b;
    }
    while (c.len - 1 > 0 && c.d[c.len - 1] == 0)
    {
        c.len--;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    char str[1000];
    int b;
    scanf("%s %d", str, &b);
    bign a = change(str);
    bign c = div(a, b);
    // 输出商
    for (int i = c.len - 1; i >= 0; i--)
    {
        printf("%d", c.d[i]);
    }
    // 输出余数
    printf(" %d\n", r);
    return 0;
}
