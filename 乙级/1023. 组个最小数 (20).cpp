/**
* @tag     PAT_B_1023
* @authors R11happy (xushuai100@126.com)
* @date    2016-9-4 20:59-21:19
* @version 1.0
* @Language C++
* @Ranking  690/686
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
    int cnt = 0;
    for(int i = 0; i<10; i++)
    {
        scanf("%d", &hashTable[i]);
        if(hashTable[i])    cnt += hashTable[i];
    }
    //从1开始找出第一个非0数输出
    for(int i = 1; i<10; i++)
    {
        if(hashTable[i])
        {
            printf("%d",i );
            hashTable[i]--;     //输出一个数，对应hashTable要记得减1
            break;
        }
    }
    cnt++;
    for(int i = 0; cnt > 0 && i<10 ; i++)
    {
        while(hashTable[i] > 0) //不能用if
        {
            printf("%d",i );
            cnt--;
            hashTable[i]--;     //输出一个数，对应hashTable要记得减1
        }
    }
    return 0;
}
