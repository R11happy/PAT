/**
* @tag     PAT_A_1067
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-13 19:42-20:31
* @version 1.0
* @Language C++
* @Ranking  1110/1225
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
    int  ans = 0;
    int fault = 0;  //记录除0以外不在本位的数量
    int k = 1;  //存放除0以外，不在本位上最小的数
    scanf("%d", &N);
    memset(hashTable, -1, sizeof(hashTable));
    for (int i = 0; i<N; i++)
    {
        scanf("%d", &num[i]);
        hashTable[num[i]] = i;
        if( i != 0 && hashTable[i] != i)   fault++;    //记录不在本位的数量
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
            while(k < N)    //要单独记录最小的位置错误的下标，不要每次遍历寻找，不然会超时
            {
                if (hashTable[k] != k)
                {
                    // swap(num[hashTable[0]], num[hashTable[ii]]);
                    swap(hashTable[0], hashTable[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
    }

    printf("%d\n", ans);
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
