/**
* @tag     PAT_A_1064
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-22 14:28-15:18
* @version 1.0
* @Language C++
* @Ranking  700/1626
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1010;
//n为结点数，number用来存放结点权值，CBT用来存放完全二叉树
//index从小到大枚举number数组
int n, number[maxn], CBT[maxn];
int num, index;
/*中序遍历*/
void inOrder(int root)
{
    if (root > n)    return; //空结点，直接返回
    inOrder(root * 2);    //左子树递归
    CBT[root] = number[index++];    //根结点处赋值number[index]
    inOrder(root * 2 + 1);  //右子树递归
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d", &number[i]);
    }
    sort(number, number + n);
    inOrder(1); //根结点的下标必须为1
                // 注意i要从1开始
    for (int i = 1; i <= n; i++)
    {
        printf("%d", CBT[i]);
        num++;
        if (num < n) printf(" ");
    }
    return 0;
}
