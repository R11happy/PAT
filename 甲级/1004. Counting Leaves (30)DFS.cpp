/**
* @tag     PAT_A_1004
* @authors R11happy (xushuai100@126.com)
* @date    2016-10-25 13:00 - 13:33
* @version 1.0
* @Language C++
* @Ranking  730/1595
* @function DFS遍历
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 110;

vector<int> G[N];   //存放树
int leaf[N] = { 0 };  //存放每层叶子结点个数
int max_h = 1;  //树的深度

                /*index为当前遍历到的结点编号,h为当前深度*/
void DFS(int index, int h)
{
    max_h = max(max_h, h);
    if (G[index].size() == 0)    //叶子结点
    {
        leaf[h]++;
        return;
    }
    //对于index结点的每个叶子结点，都递归
    for (int i = 0; i<G[index].size(); i++)
    {
        DFS(G[index][i], h + 1);
    }
}

int main(int argc, char const *argv[])
{
    int n, m, parent, child, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i<m; i++)
    {
        scanf("%d%d", &parent, &k);
        for (int j = 0; j<k; j++)
        {
            scanf("%d", &child);
            G[parent].push_back(child);
        }
    }
    DFS(1, 1);
    printf("%d", leaf[1]);
    // 注意是<=max_h
    for (int i = 2; i<=max_h; i++)    printf(" %d", leaf[i]);
    printf("\n");
    return 0;
}
