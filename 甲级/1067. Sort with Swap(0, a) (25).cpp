/**
* @tag     PAT_A_1067
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-13 19:42-
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

const int maxn = 100010;
int hashTable[maxn];
int num[maxn];

int main(int argc, char const *argv[])
{
    int N;
    int ii, ans = 0;
    int fault = 0;
    scanf("%d", &N);
    memset(hashTable, -1, sizeof(hashTable));
    for (int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
        hashTable[num[i]] = i;
        if (i != 0 && hashTable[i] != i)   fault++;    //记录不在本位的数量
    }
    while (fault > 0)
    {
        if (hashTable[0] != 0)
        {
            // swap(num[hashTable[0]], num[hashTable[hashTable[0]]]);
            swap(hashTable[0], hashTable[hashTable[0]]);
            ans++;
            fault--;
        }
        else
        {
            for (ii = 1; ii<N; ii++)
            {
                if (hashTable[ii] != ii)
                {
                    // swap(num[hashTable[0]], num[hashTable[ii]]);
                    swap(hashTable[0], hashTable[ii]);
                    ans++;
                    break;
                }
            }
            if (ii == N) break;
        }
    }

    printf("%d\n", ans);
    printf("%d\n", fault);
    // for (int i = 0; i <N; i++)
    // {
    //     printf("%d ", num[i]);
    // }
    // printf("\n");
    // for (int i = 0; i <N; i++)
    // {
    //     printf("%d ", hashTable[i]);
    // }

    return 0;
}
