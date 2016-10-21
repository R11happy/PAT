/**
* @tag     PAT_A_1020
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-21 11:48-16:23
* @version 1.0
* @Language C++
* @Ranking  645/1723
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>    //用queue要单独声明
#include <algorithm>
using namespace std;

int in[40];
int post[40];

struct node
{
    int data;
    node *lchild;
    node *rchild;
};


node *create(int postL, int postR, int inL, int inR)
{
    if (postL > postR)   return NULL;
    node *root = new node;
    root->data = post[postR];

    int k;

    /*中序序列中找到要搜索的元素*/
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == post[postR])  break;
    }

    int numLeft = k - inL;

    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);

    return root;
}

/*要输出的是层序遍历，非前序遍历
*/
void prePrint(node *T)
{
    if (T == NULL)   return;
    printf("%d ", T->data);
    prePrint(T->lchild);
    prePrint(T->rchild);
}

int N;  //结点个数
int num;    //已输出结点个数
void BFS(node *root)
{
    queue<node*> q; //注意队列里存的都是地址
    q.push(root);
    while (!q.empty())
    {
        node *now = q.front();
        q.pop();
        printf("%d", now->data);
        num++;
        if (num < N) printf(" ");
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->rchild != NULL) q.push(now->rchild);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i<N; i++)
    {
        scanf("%d", &post[i]);
    }

    for (int i = 0; i<N; i++)
    {
        scanf("%d", &in[i]);
    }

    node *T = create(0, N - 1, 0, N - 1);
    BFS(T);
    return 0;
}
