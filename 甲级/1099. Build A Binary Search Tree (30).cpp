/**
* @tag     PAT_A_1099
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-3 13:29-13:54
* @version 1.0
* @Language C++
* @Ranking  2030/542
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n;
struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
}node[maxn];
int index = 0;
vector<int> origin, level;
// inOrder确定每个结点对应的data
void inOrder(int root)
{
    if (root == -1)  return;
    inOrder(node[root].lchild);
    node[root].data = origin[index++];
        inOrder(node[root].rchild);
}
// levelOrder用于输出
void levelOrder(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        level.push_back(now);
        if (node[now].lchild != -1)  q.push(node[now].lchild);
        if (node[now].rchild != -1)  q.push(node[now].rchild);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d%d", &node[i].lchild, &node[i].rchild);
    }
    for (int i = 0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        origin.push_back(tmp);
    }
    sort(origin.begin(), origin.end());
    inOrder(0);
    levelOrder(0);
    printf("%d", node[level[0]].data);

    for (int i = 1; i<n; i++)
    {
        printf(" %d", node[level[i]].data);
    }
    printf("\n");
    return 0;
}
