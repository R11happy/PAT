/**
* @tag     PAT_A_1050
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-11 14:25-14:32
* @version 1.0
* @Language C++
* @Ranking  1010/1356
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int hashTable[128];

int main(int argc, char const *argv[])
{
    char str1[10010];
    char str2[10010];
    gets(str1);
    gets(str2);
    int lenOfStr1 = strlen(str1);
    int lenOfStr2 = strlen(str2);
    for(int i = 0; i < lenOfStr2; i++)
    {
        hashTable[str2[i]]++;
    }
    for(int i = 0; i<lenOfStr1; i++)
    {
        if(!hashTable[str1[i]]) printf("%c",str1[i] );
    }
    return 0;
}
