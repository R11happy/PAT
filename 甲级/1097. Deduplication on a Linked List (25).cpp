/**
* @tag     PAT_A_1097
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-28 21:45-22:25
* @version 1.0
* @Language C++
* @Ranking  1760/708
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
int ans[maxn], rm[maxn];
int ansCnt = 0, rmCnt = 0;

int main(int argc, char const *argv[])
{
    int begin, n, address;
    int flag = 0;
    scanf("%d%d", &begin, &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
        node[address].address = address;
    }
    int p = begin;
    int cnt = 0;
    int ansP, removeP;
    while (p != -1)
    {
        if (hashTable[abs(node[p].key)] == 0)
        {
            hashTable[abs(node[p].key)] = 1;
            ans[ansCnt++] = p;
        }
        else
        {
            rm[rmCnt++] = p;
        }
        p = node[p].next;
        cnt++;
    }

// 处理可能空链表套路
    for (int i = 0; i<ansCnt - 1; i++) printf("%05d %d %05d\n", node[ans[i]].address, node[ans[i]].key, node[ans[i + 1]].address);
    if (ansCnt > 0)  printf("%05d %d -1\n", node[ans[ansCnt - 1]].address, node[ans[ansCnt - 1]].key);

    for (int i = 0; i<rmCnt - 1; i++) printf("%05d %d %05d\n", node[rm[i]].address, node[rm[i]].key, node[rm[i + 1]].address);
    if (rmCnt > 0)  printf("%05d %d -1\n", node[rm[rmCnt - 1]].address, node[rm[rmCnt - 1]].key);
    return 0;
}
