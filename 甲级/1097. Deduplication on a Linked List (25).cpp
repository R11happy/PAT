/**
* @tag     PAT_A_1097
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-28 21:45-
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
    int address, key, next;
}node[maxn];

int hashTable[maxn];

int main(int argc, char const *argv[])
{
    int begin, n, address;
    int flag = 0;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
        node[address].address = address;
    }
    int p = begin;
    int cnt = 0;
    int ansP, removeP;
    while(p!=-1)
    {
        if(hashTable[abs(node[p].key)] == 0)
        {
            hashTable[abs(node[p],key)] = 1;
        }
        else
        {
            if(flag == 1)   int removeBegin = p;
        }
        p = node[p].next;
        cnt++;
    }
    return 0;
}
