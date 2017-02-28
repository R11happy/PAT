/**
* @tag     PAT_A_1052
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-28 20:27-21:14
* @version 1.0
* @Language C++
* @Ranking  1735/731
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
    int flag;
}node[maxn];

bool cmp(Node a, Node b)
{
    return a.key < b.key;
}


int main(int argc, char const *argv[])
{
    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].key, &node[address].next);
        node[address].address = address;
    }
    int p = begin;
    int cnt = 0;
    while (p != -1)
    {
        node[p].flag = 1;
        p = node[p].next;
        cnt++;
    }
    for (int i = 0; i < maxn; i++)
    {
        if (node[i].flag != 1) node[i].key = maxn;
    }
    sort(node, node + maxn, cmp);
    if(cnt == 0) printf("0 -1\n");  //考虑链表为空的情况
    else printf("%d %05d\n", cnt, node[0].address);
    for (int i = 0; i<cnt - 1; i++)
    {
        printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);
    }
    if(cnt>0) printf("%05d %d -1\n", node[cnt - 1].address, node[cnt - 1].key);
    return 0;
}
