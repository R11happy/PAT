/**
* @tag     PAT_B_1029
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 18:11-18:38
* @version 1.0
* @Language C++
* @Ranking  500/1194
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int HashTable[128]; //直接设置ASCII码的个数128为数组长度

int main(int argc, char const *argv[])
{
    char str1[85];
    char str2[85];
    gets(str1); //应该输入文字
    gets(str2); //实际输入文字
    int len2 = strlen(str2);
    for(int i = 0; i<len2; i++)
    {
        if(HashTable[str2[i]] == 0)
            HashTable[str2[i]] = 1;
    }
    int len1 = strlen(str1);
    for(int i = 0; i<len1; i++)
    {
        if(HashTable[str1[i]] == 0)
        {
            //小写字母要改成大写输出，并且大小写字母都要标记
            if(str1[i] >= 'a' && str1[i] <= 'z')
            {
                printf("%c",str1[i] - 32 );
                HashTable[str1[i]]++;
                HashTable[str1[i]-32]++;
            }
            // 大写字母不改变输出，但相应小写字母也要标记，防止重复输出
            else if(str1[i] >= 'A' && str1[i] <= 'Z')
            {
                printf("%c",str1[i] );
                HashTable[str1[i]]++;
                HashTable[str1[i]+32]++;
            }
            //其他情况直接标记即可
            else
            {
                printf("%c",str1[i] );
                HashTable[str1[i]]++;
            }
        }
    }
    return 0;
}
