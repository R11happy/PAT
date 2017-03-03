/**
* @tag     PAT_A_1013
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-4 1:40-1:56
* @version 1.0
* @Language C++
* @Ranking  2135/468
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
vector<int> G[maxn];
bool vis[maxn] = { false };

int currentPoint;   //将要被删除的结点

void DFS(int v)
{
    if (v == currentPoint)   return;
    vis[v] = true;
    for (int i = 0; i<G[v].size(); i++)
    {
        if (vis[G[v][i]] == false)  DFS(G[v][i]);
    }
}

int main(int argc, char const *argv[])
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i<m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i<k; i++)
    {
        memset(vis, false, sizeof(vis));
        scanf("%d", &currentPoint);
        int block = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != currentPoint && vis[i] == false)
            {
                DFS(i);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }
    return 0;
}
