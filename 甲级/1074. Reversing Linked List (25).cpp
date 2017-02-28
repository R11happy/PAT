/**
* @tag     PAT_A_1074
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-27 21:32-
* @version 1.0  17/25
* @Language C++
* @Ranking  null
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100010;
// 定义静态链表
struct Node
{
    int address, data, next;
    int order;
}node[maxn];

int main(int argc, char const *argv[])
{
    int begin, n, k, address;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int order = 0;
    for (address = begin; address != -1; address = node[address].next)
    {
        node[address].order = order+1;
        order++;
    }
    address = begin;
    int mod1Address = begin;
    int head = begin, tail = -1;
    int lastModAddress = -1;
    int flag = 0;
    while (address != -1)
    {
        if (node[address].order % k == 0)
        {
            if (flag == 0)
            {
                begin = address;
                flag = 1;
            }
            lastModAddress = mod1Address;
            tail = node[address].next;
            node[address].next = head;
            head = address;
            node[mod1Address].next = tail;
            address = tail;
        }
        else if (node[address].order % k == 1)
        {
            mod1Address = address;
            head = address;
            if (node[address].order + k <  order)
            {
                for (int i = 0; i<k - 1; i++)
                {
                    tail = node[address].next;
                    node[address].next = head;
                    head = address;
                    node[mod1Address].next = tail;
                    address = tail;
                }
                if (lastModAddress > 0) node[lastModAddress].next = head;
            }
            else break;
        }
        else address = node[address].next;

    }
    for (address = begin; address != -1; address = node[address].next)
    {
        if (node[address].next != -1) printf("%05d %d %05d\n", address, node[address].data, node[address].next);
        else printf("%05d %d %d\n", address, node[address].data, node[address].next);
    }
    return 0;
}
