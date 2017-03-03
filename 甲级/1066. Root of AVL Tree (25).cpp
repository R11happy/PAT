/**
* @tag     PAT_A_1066
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-3 18:26-19:31
* @version 1.0
* @Language C++
* @Ranking  2080/515
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int n;
const int maxn = 50;
struct Node
{
    int data;
    int lchild = -1;
    int rchild = -1;
    int height;
}node[maxn];
int origin[maxn];
int index = 0;
int newNode(int data)
{
    node[index].data = data;
    node[index].lchild = -1;
    node[index].rchild = -1;
    node[index].height = 1;
    return index++;
}

int getHeight(int root)
{
    if (root == -1)  return 0;
    else    return node[root].height;
}

int getBalanceFactor(int root)
{
    return getHeight(node[root].lchild) - getHeight(node[root].rchild);
}


void updateHeight(int root)
{
    node[root].height = max(getHeight(node[root].lchild), getHeight(node[root].rchild)) + 1;
}

void L(int &root)
{
    int tmp = node[root].rchild;
    node[root].rchild = node[tmp].lchild;
    node[tmp].lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(int &root)
{
    int tmp = node[root].lchild;
    node[root].lchild = node[tmp].rchild;
    node[tmp].rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(int &root, int data)
{
    if (root == -1)
    {
        root = newNode(data);
        return;
    }
    if (node[root].data > data)
    {
        insert(node[root].lchild, data);
        updateHeight(root);
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(node[root].lchild) == 1)
            {
                R(root);
            }
            else if (getBalanceFactor(node[root].lchild) == -1)
            {
                L(node[root].lchild);
                R(root);
            }
        }
    }
    else
    {
        insert(node[root].rchild, data);
        updateHeight(root);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(node[root].rchild) == -1)   L(root);
            else if (getBalanceFactor(node[root].rchild == 1))
            {
                R(node[root].rchild);
                L(root);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    int root = -1;
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &origin[i]);
        insert(root, origin[i]);
    }
    printf("%d\n", node[root].data);
    return 0;
}

