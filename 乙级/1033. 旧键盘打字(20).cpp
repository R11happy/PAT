/**
* @tag     PAT_B_1033
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-2 18:45-19:09
* @version 1.0
* @Language C++
* @Ranking  520/1139
* @function null
*/



#include <cstdio>
#include <cstdlib>
#include <cstring>

const int Max = 100000;
int HashTable[128];

int main(int argc, char const *argv[])
{
    char broken[Max+10];
    char input[Max+10];
    gets(broken);
    gets(input);
    int len_bro = strlen(broken);
    int len_in = strlen(input);

    for(int i = 0; i<len_bro; i++)
    {
        HashTable[broken[i]] = 1;
        //大写字母无法打出
        if(broken[i] == '+')
        {
            for(int j = 'A'; j<='Z'; j++)    HashTable[j] = 1;  //注意是<='Z' 非<'Z'
        }
        if(broken[i] >= 'A' && broken[i] <= 'Z')    HashTable[broken[i] + 32] = 1;
    }

    for(int i = 0; i<len_in; i++)
    {
        if(HashTable[input[i]] == 0)    printf("%c",input[i] );
    }

    printf("\n");   //无字符打出，则输出空行
    return 0;
}
