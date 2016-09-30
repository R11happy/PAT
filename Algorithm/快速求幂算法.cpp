#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

long long Power(int x, int n)
{
    long long y = 1;
    int tmp;
    do
    {
        tmp = n % 2;
        n = floor(n / 2);   //需要cmath头文件

        if (tmp == 1)
        {
            y = y * x;
        }

        x = x*x;
    } while (n != 0);
    return y;
}

int main(int argc, char const *argv[])
{
    int x, n;
    long long y;
    printf("Please input x:\n");
    scanf("%d", &x);
    printf("Please input y:\n");
    scanf("%d", &n);
    y = Power(x, n);
    printf("The result: %lld", y);
    return 0;
}
