/**
* @tag     PAT_A_1043
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-2 20:30-22:00
* @version 1.0
* @Language C++
* @Ranking  2000/558
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
}node[maxn];

int index = 0;
int newNode(int v)
{
    node[index].data = v;
    node[index].lchild = -1;
    node[index].rchild = -1;
    return index++;
}

void insert(int &root, int data)
{
    if (root == -1)
    {
        root = newNode(data);
        return;
    }
    if (data < node[root].data)  insert(node[root].lchild, data);
    else insert(node[root].rchild, data);
}
int n;
vector<int> origin, pre, preM, post, postM;
void preOrder(int root, vector<int>& vi)
{
    if (root == -1)  return;
    vi.push_back(node[root].data);
    preOrder(node[root].lchild, vi);
    preOrder(node[root].rchild, vi);
}
void preOrderMirror(int root, vector<int>& vi)
{
    if (root == -1)  return;
    vi.push_back(node[root].data);
    preOrderMirror(node[root].rchild, vi);
    preOrderMirror(node[root].lchild, vi);
}

void postOrder(int root, vector<int>& vi)
{
    if (root == -1)  return;
    postOrder(node[root].lchild, vi);
    postOrder(node[root].rchild, vi);
    vi.push_back(node[root].data);
}
void postOrderMirror(int root, vector<int>& vi)
{
    if (root == -1)  return;
    postOrderMirror(node[root].rchild, vi);
    postOrderMirror(node[root].lchild, vi);
    vi.push_back(node[root].data);
}
int main(int argc, char const *argv[])
{
    int data;
    int root = -1;
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre)
    {
        printf("YES\n");
        printf("%d", post[0]);
        for (int i = 1; i<post.size(); i++)
        {
            printf(" %d", post[i]);
        }
        printf("\n");
    }
    else if (origin == preM)
    {
        printf("YES\n");
        printf("%d", postM[0]);
        for (int i = 1; i<postM.size(); i++)
        {
            printf(" %d", postM[i]);
        }
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}
