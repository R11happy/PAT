/**
* @tag     PAT_B_1005
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-3 21:52-22:26
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int HashTable[110];
int input[110];
bool cmp(int a, int b)
{
    return a>b;
}


int main(int argc, char const *argv[])
{
    int i, j, t, K;
    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf("%d", &t);
        input[i] = t;
        while (t != 1)
        {

            if (t % 2 == 0) t /= 2;
            else    t = (3 * t + 1) / 2;
            if (t > 100)    continue;
            HashTable[t] = 1;
        }
    }
    //从大到小排序
    sort(input, input + K, cmp);
    for (j = 0; j<K; j++)
    {
        if (HashTable[input[j]] == 0)
        {
            printf("%d", input[j]);
            break;
        }
    }
    for (j++; j<K; j++)
    {
        if (HashTable[input[j]] == 0)
        {
            printf(" %d", input[j]);
        }
    }
    return 0;
}
