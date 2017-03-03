/**
* @tag     PAT_A_1110
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-3 13:56-15:12
* @version 2.0
* @Language C++
* @Ranking  2055/530
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
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
int cnt = 0;
int lastNode = 0;
void levelOrder(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now != -1)
        {
            lastNode = now;
            cnt++;
        }
        else
        {
            if (cnt == n)
            {
                printf("YES %d\n", lastNode);
            }
            else    printf("NO %d\n", root);
            break;
        }
        q.push(node[now].lchild);
        q.push(node[now].rchild);
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

    return 0;
}
