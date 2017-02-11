/**
* @tag     PAT_B_1039
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 22:23-22:33
* @version 1.0
* @Language C++
* @Ranking  560/1026
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 1000;
int HashTable[128];
int sub;    //记录缺少的珠子个数

int main(int argc, char const *argv[])
{
    char str1[Max+10];
    char str2[Max+10];
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    //统计摊主各个珠子数量
    for(int i = 0; i<len1; i++)
    {
        HashTable[str1[i]]++;
    }

    for(int i = 0; i<len2; i++)
    {
        if(HashTable[str2[i]] == 0) sub++;  //当发现某一珠子数量为0，缺少的珠子数加1
        else    HashTable[str2[i]]--;
    }
    if(!sub) printf("Yes %d",len1-len2);
    else printf("No %d", sub);
    return 0;
}
