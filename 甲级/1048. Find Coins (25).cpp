/**
* @tag     PAT_A_1048
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-11 14:42-15:05
* @version 1.0
* @Language C++
* @Ranking  1035/1319
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

// 段错误 == 数组越界
int hashTable[10010];   //一开始开510的数组，段错误

int main(int argc, char const *argv[])
{
    int N, M;
    int flag = 0;
    int coin[100010];
    scanf("%d%d", &N, &M);
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &coin[i]);
        hashTable[coin[i]]++;
    }
    sort(coin, coin+N);
    for(int i = 0; i<N; i++)
    {
        if(hashTable[coin[i]] && hashTable[M - coin[i]])
        {
            // e.g. 4 = 2+2， 但2只有一个的情况
            if(coin[i] == M - coin[i] && hashTable[coin[i]] == 1) break;
            else{
                printf("%d %d\n",coin[i], M-coin[i] );
                flag = 1;
                break;
            }
        }
    }
    if(!flag) printf("No Solution\n");
    return 0;
}


