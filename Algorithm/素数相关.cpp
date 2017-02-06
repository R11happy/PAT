///////////
// 素数的判断 //
// ///////////

bool isPrime(int n)
{
    if(n <= 1)  return false;
    int sqr = (int)sqrt(1.0*n);
    for(int i = 2; i<=sqr; i++)
    {
        if(n % i == 0)  return false;
    }
    return true;
}

// 筛法获取素数表
const int maxn = 101;   //表长
int prime[maxn], pNum = 0;  //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0}; //如果i为素数，则 p[i]为false；否则，p[i]为true
void Find_Prime()
{
    for(int i = 2; i<maxn; i++)
    {
        if(p[i] == false)
        {
            prime[pNum++] = i;
            for(int j = i+1; j<maxn; j+=i)
            {
                p[j] = true;
            }
        }
    }
}

// 求100以内所有素数
#include <cstdio>
const int maxn = 101;   //表长
int prime[maxn], pNum = 0;  //prime数组存放所有素数，pNum为素数个数
bool p[maxn] = {0}; //如果i为素数，则 p[i]为false；否则，p[i]为true
void Find_Prime()
{
    for(int i = 2; i<maxn; i++)
    {
        if(p[i] == false)
        {
            prime[pNum++] = i;
            for(int j = i+i; j<maxn; j+=i)
            {
                p[j] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Find_Prime();
    for(int i = 0; i<pNum; i++)
    {
        printf("%4d ",prime[i] );
        if((i+1) % 5 == 0)  printf("\n");
    }
    return 0;
}
