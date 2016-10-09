/**
* @tag     PAT_B_1023
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-4 20:59-
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

int hashTable[10];

int main(int argc, char const *argv[])
{
    for (int i = 0; i<10; i++)
    {
        scanf("%d", &hashTable[i]);
    }
    for (int i = 1; i<10; i++)
    {
        if (hashTable[i])
        {
            printf("%d", i);
            hashTable[i]--;
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < hashTable[i]; j++)
        {
            printf("%d", i);
        }
    }
    return 0;
}
