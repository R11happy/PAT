/**
* @tag     PAT_B_1043
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 23:56-00:08
* @version 1.0
* @Language C++
* @Ranking  600/884
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 10000;
int HashTable[128];

int main(int argc, char const *argv[])
{
    int cnt = 0;    //记录最多输出几组
    char str[Max+10];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i<len; i++)
    {
        HashTable[str[i]]++;
        if(HashTable[str[i]] > cnt)  cnt = HashTable[str[i]];
    }

    for(int i = 0; i<cnt; i++)
    {
        if(HashTable['P'])
        {
            printf("P");
            HashTable['P']--;
        }
        if(HashTable['A'])
        {
            printf("A");
            HashTable['A']--;
        }
        if(HashTable['T'])
        {
            printf("T");
            HashTable['T']--;
        }
        if(HashTable['e'])
        {
            printf("e");
            HashTable['e']--;
        }
        if(HashTable['s'])
        {
            printf("s");
            HashTable['s']--;
        }
        if(HashTable['t'])
        {
            printf("t");
            HashTable['t']--;
        }
    }
    return 0;
}
