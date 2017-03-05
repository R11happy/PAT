/**
* @tag     PAT_A_1127
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-5 14:25-14:58
* @version 1.0
* @Language C++
* @Ranking  null
* @function null
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 50;
vector<int> post, in, level;
int hashTable[128];
int maxLayer = 0;
struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
    int layer;
}node[maxn];

int cnt = 0;
int newNode(int data)
{
    node[cnt].data = data;
    node[cnt].lchild = -1;
    node[cnt].rchild = -1;
    return cnt++;
}

int createTree(int postL, int postR, int inL, int inR)
{
    if (postL > postR)   return -1;
    if (inL > inR)   return -1;
    int root = newNode(post[postR]);
    int k = -1;
    for (int i = inL; i <= inR; i++)
    {
        if (in[i] == node[root].data)
        {
            k = i;
            break;
        }
    }
    int leftNum = k - inL;  //一定要记得减去inL
    node[root].lchild = createTree(postL, postL + leftNum - 1, inL, k - 1);
    node[root].rchild = createTree(postL + leftNum, postR - 1, k + 1, inR);
    return root;
}

void levelOrder(int root)
{
    queue<int> q;
    node[root].layer = 1;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        level.push_back(node[now].data);
        int h = node[now].layer;
        hashTable[h]++;
        maxLayer = max(maxLayer, h);
        if (node[now].lchild != -1)
        {
            int lchild = node[now].lchild;
            node[lchild].layer = node[now].layer+1;
            q.push(lchild);
        }
        if (node[now].rchild != -1)
        {
            int rchild = node[now].rchild;
            node[rchild].layer = node[now].layer+1;
            q.push(rchild);
        }

    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int tmp;
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &tmp);
        in.push_back(tmp);
    }
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &tmp);
        post.push_back(tmp);
    }

    int root = createTree(0, n - 1, 0, n - 1);
    levelOrder(root);
    int layer = 1;
    for(int i = 0; i<n; i+=hashTable[layer],layer++)
    {
        if(layer % 2 == 1)  reverse(level.begin(), level.begin()+hashTable[layer]);
    }
    printf("%d", level[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", level[i]);
    }
    printf("\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d: %d\n",node[i].data, node[i].layer );
    }
    return 0;
}

