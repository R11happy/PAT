/**
* @tag     PAT_B_1042
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 22:38-22:48
* @version 1.0
* @Language C++
* @Ranking  580/937
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 1000;
int HashTable[128];

int main(int argc, char const *argv[])
{
    int MaxIndx, MaxValue=0;
    char str[Max+10];
    gets(str);
    int len = strlen(str);
    for(int i = 0; i<len; i++)
    {
        HashTable[str[i]]++;
        //对大写字母，对应小写字母哈希表同样加1
        if(str[i] >= 'A' && str[i] <= 'Z')  HashTable[str[i]+32]++;
    }
    //只在小写英文字母中排查，并更新
    for(int i = 'a'; i<='z'; i++)
    {
        if(HashTable[i] > MaxValue)
        {
            MaxValue = HashTable[i];
            MaxIndx = i;
        }
    }


    printf("%c %d\n",(char)MaxIndx, MaxValue );
    return 0;
}
