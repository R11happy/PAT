/**
* @tag     PAT_A_1053
* @authors R11happy (xushuai100@126.com)
* @date     2017-3-2 21:07-21:46
* @version 1.0
* @Language C++
* @Ranking  1975/578
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, m, s;

int path[maxn];

struct Node
{
    int weight;
    vector<int> children;
}node[maxn];

// 按权重又大到小排序
bool cmp(int a, int b)
{
    return node[a].weight > node[b].weight;
}

void DFS(int index, int cnt, int sum)
{
    if (sum > s) return;
    if (sum == s)
    {
        if(node[index].children.size() != 0)    return; //只有一条路径完全结束后，才进行输出处理
        printf("%d", node[path[0]].weight);
        for (int i = 1; i<cnt; i++)
        {
            printf(" %d", node[path[i]].weight);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i<node[index].children.size(); i++)
    {
        int child = node[index].children[i];
        path[cnt] = child;
        DFS(child, cnt + 1, sum + node[child].weight);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i<n; i++)
    {
        int weight;
        scanf("%d", &weight);
        node[i].weight = weight;
    }
    for (int i = 0; i<m; i++)
    {
        int id, num;
        scanf("%d%d", &id, &num);
        for (int j = 0; j<num; j++)
        {
            int child;
            scanf("%d", &child);
            node[id].children.push_back(child);
        }
        sort(node[id].children.begin(), node[id].children.end(), cmp);
    }
    path[0] = 0;
    DFS(0, 1, node[0].weight);
    return 0;
}
