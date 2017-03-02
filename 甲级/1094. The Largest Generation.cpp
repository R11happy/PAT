/**
* @tag     PAT_A_1094
* @authors R11happy (xushuai100@126.com)
* @date    2017-3-2 20:32-20:52
* @version 1.0
* @Language C++
* @Ranking  1945/593
* @function null
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, m;
vector<int> children[maxn];
int level[maxn];

int maxDepth, maxPopulation;

void DFS(int index, int depth)
{
    if(children[index].size() == 0)
    {
        level[depth]++;
        if(level[depth] > maxPopulation)
        {
            maxDepth = depth;
            maxPopulation = level[depth];
        }
        return;
    }
    level[depth]++;
    if(level[depth] > maxPopulation)
    {
        maxDepth = depth;
        maxPopulation = level[depth];
    }
    for(int i = 0; i<children[index].size(); i++)
    {
        DFS(children[index][i], depth+1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; i++)
    {
        int num, id, child;
        scanf("%d%d", &id, &num);
        for(int j = 0; j<num; j++)
        {
            scanf("%d", &child);
            children[id].push_back(child);
        }
    }
    DFS(1,1);
    printf("%d %d\n",maxPopulation, maxDepth );
    return 0;
}
