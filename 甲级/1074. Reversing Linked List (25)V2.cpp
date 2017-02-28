/**
* @tag     PAT_A_1074
* @authors R11happy (xushuai100@126.com)
* @date    2017-2-28 13:40-17:02
* @version 2.0
* @Language C++
* @Ranking  1710/751
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct Node
{
    int address, data, next;
    int order;  //定义在链表上的序号，无效结点记为maxn
}node[maxn];

bool cmp(Node a, Node b)
{
    return a.order < b.order;   //按order从小到大排序
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i<maxn; i++)
    {
        node[i].order = maxn;   //初始化全部为无效结点
    }
    int begin, n, k, address;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    int p = begin, count = 0;   //count计数有效结点的数目
                                // 找出单链表的所有有效结点
    while (p != -1)
    {
        node[p].order = count++;
        p = node[p].next;
    }
    sort(node, node + maxn, cmp); //按单链表从头到尾顺序排序
    n = count;
    for (int i = 0; i<n / k; i++)
    {
        // 第i块倒着输出
        for (int j = (i + 1)*k - 1; j>i*k; j--)
        {
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        }
        // 每一块最后一个结点的next地址的处理
        printf("%05d %d ", node[i*k].address, node[i*k].data);
        if (i < n / k - 1)
        {
            printf("%05d\n", node[(i + 2)*k - 1].address);
        }
        // 最后一个块
        else
        {
            if (n%k == 0)
            {
                printf("-1\n"); //恰好是最后一个结点，输出-1
            }
            //剩下不完整的块按原先顺序输出
            else
            {
                printf("%05d\n", node[(i + 1)*k].address);
                for (int i = n / k * k; i<n; i++)
                {
                    printf("%05d %d ", node[i].address, node[i].data);
                    if (i<n - 1)
                    {
                        printf("%05d\n", node[i + 1].address);
                    }
                    else
                    {
                        printf("-1\n");
                    }
                }
            }
        }
    }
    return 0;
}
