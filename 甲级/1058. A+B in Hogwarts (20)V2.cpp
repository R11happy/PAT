/**
* @tag     PAT_A_1058
* @authors R11happy (xushuai100@126.com)
* @date    2016-8-20 00:13-00:27
* @version 1.0
* @Language C++
* @Ranking  280/2992
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int a[3], b[3], c[3];
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    int carry = 0;  //进位
    c[2] = (a[2] + b[2]) % 29;
    carry = (a[2] + b[2]) / 29;
    c[1] = (a[1] + b[1] + carry) % 17;
    carry = (a[1] + b[1] + carry) / 17;
    c[0] = a[0] + b[0] + carry;
    printf("%d.%d.%d\n", c[0], c[1], c[2] );
    return 0;
}

c[i] = (a[i] + b[i] +carry) % mod;
carry = (a[i] + b[i] + carry) / mod;
