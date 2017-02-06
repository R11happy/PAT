/**
* @tag     PAT_A_1086
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-22 4:56-6:10
* @version 1.0
* @Language C++
* @Ranking  670/1674
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;


struct node
{
    int data;
    node *lchild;
    node *rchild;
};

int n;
int num;
int pre[40], in[40];

node *create(int preL, int preR, int inL, int inR)
{
    if (preL > preR) return NULL;
    node *root = new node;
    root->data = pre[preL];

    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == pre[preL]) break;
    }

    int numLeft = k - inL;
    root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
    return root;    //不要忘记返回root
}

void postOrder(node *root)
{
    if (root == NULL)    return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d", root->data);
    num++;
    if (num < n) printf(" ");
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    char str[5];
    stack<int> st;
    int x, preIndex = 0, inIndex = 0;
    for (int i = 0; i<n * 2; i++)
    {
        scanf("%s", str);
        if (strcmp(str, "Push") == 0)
        {
            scanf("%d", &x);
            pre[preIndex++] = x;
            st.push(x);
        }
        else
        {
            in[inIndex++] = st.top();
            st.pop();
        }
    }

    node *root = create(0, n - 1, 0, n - 1);
    postOrder(root);
    return 0;
}

/*
Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
 */
