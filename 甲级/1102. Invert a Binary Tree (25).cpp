/**
* @tag     PAT_A_1102
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-1 22:40-24:00
* @version 1.0
* @Language C++
* @Ranking  1845/660
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 15;
int hashTable[15] = { 0 };
int addr[15] = {0};
struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
}node[maxn];

int level[maxn], pre[maxn];

int levelIndex = 0;
void LeveOrder(int root)
{
    queue<int> T;
    T.push(root);
    while (!T.empty())
    {
        int now = T.front();
        T.pop();
        level[levelIndex++] = now;
        if (node[now].lchild != -1)  T.push(node[now].lchild);
        if (node[now].rchild != -1)  T.push(node[now].rchild);
    }
}

int preIndex = 0;
void preOrder(int root)
{
    if(root == -1)  return;
    preOrder(node[root].lchild);
    pre[preIndex++] = node[root].data;
    preOrder(node[root].rchild);
}

// void LayerOrder(int root)
// {
//     queue<int> q;
//     q.push(root);
//     while(root != -1)
//     {
//         int now = q.front();
//         q.pop();
//         printf("%d ",level[now].data );
//         if(node[root].lchild != -1) q.push(level[root].lchild);
//         if(node[root].rchild != -1) q.push(level[root].rchild);
//     }
// }

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    getchar();
    char lchild, rchild;
    for (int i = 0; i<n; i++)
    {
        node[i].data = i;
        scanf("%c", &lchild);
        if (lchild >= '0' && lchild <= '9')
        {
            node[i].rchild = lchild - '0';
            hashTable[lchild-'0'] = 1;
        }
        else node[i].rchild = -1;
        getchar();
        scanf("%c", &rchild);
        if (rchild >= '0' && rchild <= '9')
        {
            node[i].lchild = rchild - '0';
            hashTable[rchild-'0'] = 1;
        }
        else node[i].lchild = -1;
        getchar();
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
    LeveOrder(root);
    printf("%d", level[0]);
    for (int i = 1; i<n; i++)
    {
        printf(" %d", level[i]);
    }
    printf("\n");
    preOrder(root);
    printf("%d", pre[0]);
    for (int i = 1; i<n; i++)
    {
        printf(" %d", pre[i]);
    }
    printf("\n");
    return 0;
}
