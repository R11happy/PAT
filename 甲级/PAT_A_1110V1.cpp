/**
* @tag     PAT_A_1110
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-3 13:56-15:12
* @version 1.0
* @Language C++
* @Ranking  2055/530
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50;
int hashTable[maxn] = { false };
struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
}node[maxn];
int n;
int level[maxn];

void levelOrder(int root)
{
    int index = 1;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        level[index] = now;
        index++;
        if (node[now].lchild != -1)  q.push(node[now].lchild);
        if (node[now].rchild != -1)  q.push(node[now].rchild);
    }
}

int getNum(char str[])
{
    int len = strlen(str);
    int tmp = 0;
    for (int i = 0; i<len; i++)
    {
        tmp = tmp * 10 + str[i] - '0';
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    getchar();
    char lchild[4], rchild[4];
    for (int i = 0; i<n; i++)
    {
        // 注意，输入不一定是1位数
        scanf("%s %s", lchild, rchild);
            if (strcmp(lchild, "-") != 0)
            {
                int num = getNum(lchild);
                node[i].lchild = num;
                hashTable[num] = 1;
            }
            else node[i].lchild = -1;
            if (strcmp(rchild, "-") != 0)
            {
                int num = getNum(rchild);
                node[i].rchild = num;
                hashTable[num] = 1;
            }
            else node[i].rchild = -1;
    }
    int root = 0;
    for (int i = 0; i<n; i++)
    {
        if (hashTable[i] == 0)
        {
            root = i;
            break;
        }
    }
    levelOrder(root);
    int flag = 0;
    for (int i = 1; i<n; i++)
    {
        if (i * 2 <= n)
        {
            if (node[level[i]].lchild != level[i * 2])
            {
                flag = 1;
                break;
            }
        }
        if (i * 2 + 1 <= n)
        {
            if (node[level[i]].rchild != level[i * 2 + 1])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("YES %d\n", level[n]);
    }
    else
    {
        printf("NO %d\n", root);
    }
    return 0;
}
