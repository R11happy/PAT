/**
* @tag     PAT_B_1013
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-8 18:15-
* @version 1.0
* @Language C++
* @Ranking  870/400
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 1001000;   //end <= 1e4只是说最多10000个素数，但第10000个素数是多大不确定，建议数组先开大一点，只开10010肯定不够
int prime[maxn];
bool p[maxn] = { 0 };
//筛法获取素数表
void Find_Prime(int end)
{
    int pNum = 0;
    for (int i = 2; i<maxn && pNum<end; i++)
    {
        if (p[i] == false)
        {
            prime[pNum++] = i;
            for (int j = i + i; j<maxn; j += i)
            //i的所有整数倍全部筛掉
            {
                p[j] = true;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int begin, end;
    int cnt = 0;
    scanf("%d %d", &begin, &end);
    Find_Prime(end);

    for(int i = begin-1; i<end; i++)
    {
        printf("%d",prime[i] );
        cnt++;
        if(cnt % 10 != 0 && i<end-1)    printf(" ");    //只有每到行末，才输出空格
        else printf("\n");
    }
    return 0;
}
