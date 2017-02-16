/**
* @tag     PAT_AA_1029
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-16 20:04-20:24
* @version 1.0
* @Language C++
* @Ranking  1240/1109
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 10000100;

LL num1[maxn];
LL num2[maxn];
LL num[maxn];

int main(int argc, char const *argv[])
{
    int N1, N2;
    int i = 0, j = 0;
    int index = 0;
    scanf("%d", &N1);
    for(int i = 0; i<N1; i++)
    {
        scanf("%lld", &num1[i]);
    }
    scanf("%d", &N2);
    for(int i = 0; i<N2; i++)
    {
        scanf("%lld", &num2[i]);
    }
    sort(num1, num1+N1);
    sort(num2, num2+N2);
    int medianIndex = (N1+N2-1)/2;
    while(i < N1 && j < N2)
    {
        if(num1[i] <= num2[j]) num[index++] = num1[i++];
        else num[index++] = num2[j++];
    }
    while(i < N1) num[index++] = num1[i++];
    while(j < N2) num[index++] = num2[j++];
    printf("%lld\n", num[medianIndex] );
    return 0;
}
