/**
* @tag     PAT_A_1041
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-11 14:05-14:18
* @version 1.0
* @Language C++
* @Ranking  990/1381
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int hashTable[10010];

int main(int argc, char const *argv[])
{
    int n, num[100010];
    int flag = 0;
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &num[i]);
        hashTable[num[i]]++;
    }
    for(int i = 0; i<n; i++)
    {
        if(hashTable[num[i]] == 1)
        {
            printf("%d\n",num[i] );
            flag = 1;
            break;
        }
    }
    if(flag == 0)   printf("None\n");
    return 0;
}
