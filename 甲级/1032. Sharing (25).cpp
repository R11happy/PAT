/**
* @tag     PAT_A_1032
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-9 21:41-22:05
* @version 1.0
* @Language C++
* @Ranking  565/1874
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int maxn = 100010;
// 数据结构采用静态链表
struct Node
{
    char data;
    int next;
    int flag = 0;
}node[maxn], tmp;

int main(int argc, char const *argv[])
{
    int s1, s2, N;
    int address = -1;
    int p, q;
    int flag = 0;
    scanf("%d %d %d", &s1, &s2, &N);
    // 读入地址，数据和下一个结点地址
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &address);
        getchar();  //接收多余空格
        scanf("%c %d", &node[address].data, &node[address].next);
    }
    // 遍历第一个链表
    for (p = s1; p != -1; p = node[p].next)
    {
        node[p].flag = 1;
    }
    // 遍历第二个链表
    for (q = s2; q != -1; q = node[q].next)
    {
        // 发现第一个相同结点就跳出
        if (node[q].flag == 1)
        {
            flag = 1;   //标记发现相同结点
            break;
        }
    }
    if (flag == 1)   printf("%05d\n", q);   //注意格式 %05d
    else printf("-1\n");
    return 0;
}
